#include <bits/stdc++.h>
using namespace std;
using namespace std;
#define zhalok Zhalok
#define inf INT_MAX
#define ll long long int
#define ull unsigned long long
#define loop(i, a, b) for (ll i = a; i < b; i++)
#define negloop(i, a, b) for (ll i = a; i >= b; i--)
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define pb push_back
#define be begin()
#define en end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define ff first
#define ss second
#define MOD 1000000007
#define sz 10001
#define ub upper_bound
#define lb lower_bound
#define all(v) v.begin(), v.end()
#define eps 1e-8
#define pi acos(-1.0)

int grid[500][500];
int prefixSumGrid[500][500];
int n, m;

int calculateEdgeRowCost(int row, int col1, int col2)
{
    int len = col2 - col1 + 1;
    int numberOfOnes = prefixSumGrid[col2 - 1] - prefixSumGrid[col1];
    return abs((len - 2) - numberOfOnes);
}

int calculateMiddleRowCost(int row, int col1, int col2)
{
    return (2 - (grid[row][col1] + grid[row][col2])) + (prefixSumGrid[row][col2 - 1] - prefixSumGrid[row][col1]);
}

int calculateCurRowCost(int row, int col1, int col2)
{
    int row2 = row;
    int row1 = row - 4;
    int edge1 = calculateEdgeRowCost(row1, col1, col2);
    int edge2 = calculateEdgeRowCost(row2, col1, col2);
    int ans = edge1 + edge2;
    for (int i = row1 + 1; i < row2; i++)
        ans += calculateMiddleRowCost(i, col1, col2);
    return ans;
}

int calculateMergedRowCost(int row, int col1, int col2, int prevAns)
{
    int ans = prevAns;

    ans -= calculateEdgeRowCost(row - 1, col1, col2);
    ans += calculateMiddleRowCost(row - 1, col1, col2);
    ans += calculateEdgeRowCost(row, col1, col2);

    return ans;
}

void solve()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            grid[i][j] = c - '0';
            prefixSumGrid[i][j] = grid[i][j];
            if (j)
                prefixSumGrid[i][j] += prefixSumGrid[i][j - 1];
        }
    }

    int ans = n * m;

    for (int i = 0; i + 3 < m; i++)
    {
        for (int j = i + 3; j < m; j++)
        {
            int tempAns = n * m;
            int curAns = calculateCurRow(4, i, j);
            tempAns = min(tempAns, curAns);
            for (int k = 5; k < n; k++)
            {
                int curRowAns = calculateCurRowCost(k, i, j);
                int mergedAns = calculateMergedRowCost(k, i, j, curAns);
                curAns = min(curRowAns, mergedAns);
                tempAns = min(tempAns, curAns);
            }
            ans = min(ans, tempAns);
        }
    }
    cout << ans << endl;
}

int main()
{
    freopen64("input.txt", "r", stdin);
    freopen64("output.txt", "w", stdout);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
        solve();
}