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

int maxHistogramRectangle(vi &v)
{
    int n = v.size();
    int left[n];
    int right[n];
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (st.size() && v[st.top()] >= v[i])
            st.pop();

        if (st.size())
            left[i] = st.top() + 1;
        else
            left[i] = 0;

        st.push(i);
    }
    while (st.size())
        st.pop();

    for (int i = v.size() - 1; i >= 0; i--)
    {
        while (st.size() && v[st.top()] >= v[i])
            st.pop();

        if (st.size())
            right[i] = st.top() - 1;
        else
            right[i] = n - 1;

        st.push(i);
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int lo = left[i];
        int hi = right[i];
        int temp_ans = v[i] * (hi - lo + 1);
        ans = max(ans, temp_ans);
    }

    return ans;
}

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.size() == 0)
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int grid[n][m];
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                grid[i][j] = matrix[i][j] - '0';
        vi v;

        for (int i = 1; i < n; i++)
        {
            v.clear();

            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                    grid[i][j] += grid[i - 1][j];
                v.push_back(grid[i][j]);
            }

            int temp_ans = maxHistogramRectangle(v);
            ans = max(ans, temp_ans);
        }

        return ans;
    }
};

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vi v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int k;
    cin >> k;

    Solution sol;
    cout << sol.maxResult(v, k) << endl;
}
