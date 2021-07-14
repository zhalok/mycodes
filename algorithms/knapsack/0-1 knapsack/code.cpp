#include <bits/stdc++.h>
using namespace std;
using namespace std;
#define zhalok Zhalok
#define INF 1000
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

ll minn(ll a, ll b)
{
    return a < b ? a : b;
}

ll maxx(ll a, ll b)
{
    return a > b ? a : b;
}

vi C;
int mem[4][48];

int evaluate_table(int i, int W, int n)
{
    if (W < 0)
        return INF;
    if (i == n)
    {
        if (W == 0)
            return 0;
        return INF;
    }

    return mem[i][W];
}

int coin_change_iterative(int n, int target)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int w = 0; w <= target; w++)
        {

            int res_1 = 1 + evaluate_table(i + 1, w - C[i], n);
            int res_2 = evaluate_table(i + 1, w, n);
            mem[i][w] = min(res_1, res_2);
        }
    }

    return mem[0][target];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        C.push_back(x);
    }
    // for (auto x : v)
    //     cout << x << " ";
    int w;
    cin >> w;
    memset(mem, -1, sizeof mem);
    coin_change_iterative(n, w);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <= 47; j++)
            cout << mem[i][j] << " ";
        cout << endl;
    }
}