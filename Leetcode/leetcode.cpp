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

int N;
int mem[201];
int dp(int idx)
{
    if (idx >= N)
        return 1;
    if (mem[idx] != -1)
        return mem[idx];
    return mem[idx] = dp(idx + 1) + dp(idx + 2);
}

class Solution
{
public:
    int climbStairs(int n)
    {
        memset(mem, -1, sizeof mem);
        return dp(0);
    }
};

// int main()
// {

//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     int n, m;
//     cin >> n >> m;
//     vector<vi> v;
//     for (int i = 0; i < n; i++)
//     {
//         vi temp;
//         for (int j = 0; j < m; j++)
//         {
//             int x;
//             cin >> x;
//             temp.push_back(x);
//         }
//         v.push_back(temp);
//     }

//     Solution Solution;
//     cout << Solution.uniquePathsIII(v) << endl;
// }
