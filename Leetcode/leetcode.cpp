#include <bits/stdc++.h>
using namespace std;
using namespace std;
#define zhalok Zhalok
#define inf 1000000
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
    return (a < b) ? a : b;
}

vll v;
ll mem[10001];
int n;

ll dp(int idx)
{
    if (idx >= v.size() - 1)
        return 0;
    if (mem[idx] != -1)
        return mem[idx];
    int mn = idx + 1;
    int mx = idx + v[idx];
    mx = minn(v.size() - 1, mx);
    ll ans = inf;
    for (int i = mn; i <= mx; i++)
        ans = minn(ans, 1 + dp(i));

    return mem[idx] = ans;
}

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        for (auto x : nums)
            v.push_back(x);
        memset(mem, -1, sizeof mem);
        return dp(0);
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

    Solution solution;
    cout << solution.jump(v) << endl;
}
