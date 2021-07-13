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

ll minn(ll a, ll b)
{
    return a < b ? a : b;
}

ll maxx(ll a, ll b)
{
    return a > b ? a : b;
}

ll v[1000001];
ll sparse_table[1000001][20];
ll logval[1000001];

void create_sparse_table(int n)
{

    logval[1] = 0;
    for (int i = 2; i <= 1000001; i++)
        logval[i] = logval[i / 2] + 1;

    for (int i = 0; i <= 1000000; i++)
        sparse_table[i][0] = v[i];

    for (int j = 1; j <= 19; j++)
        for (int i = 0; i + (1 << j) <= 1000000; i++)
            sparse_table[i][j] = minn(sparse_table[i][j - 1], sparse_table[i + (1 << (j - 1))][j - 1]);
}

ll query(int l, int r)
{
    // int len = logval[(r - l + 1)];
    int len = log2(r - l + 1);

    // cout << len << " " << (r - l + 1) << " " << sparse_table[l][len] << " " << sparse_table[r - (1 << len) + 1][len] << endl;
    return minn(sparse_table[l][len], sparse_table[r - (1 << len) + 1][len]);
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> v[i];

    create_sparse_table(n);
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //         cout << sparse_table[i][j] << " ";
    //     cout << endl;
    // }

    int m;
    cin >> m;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        // l--;
        // r--;
        cout << query(l, r) << endl;
    }
}

int main()
{

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    memset(sparse_table, inf, sizeof sparse_table);
    memset(v, inf, sizeof v);

    solve();
}
