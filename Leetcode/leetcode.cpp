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

string st;

int mem[100001];

int mx, mn;

bool dp(int idx)
{
    if (idx >= st.size() - 1 && st[st.size() - 1] == '0')
        return true;
    if (mem[idx] != -1)
        return mem[idx];
    int lo = idx + mn;
    int hi = idx + mx;
    bool ans = false;
    for (int i = lo; i <= hi; i++)
        if (st[i] == '0')
            ans |= dp(i);
    return mem[idx] = ans;
}

class Solution
{
public:
    bool canReach(string s, int minJump, int maxJump)
    {
    }
};

// int main()
// {

//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     int n;
//     cin>>n;
//     vi v;
//     for(int i=0;i<n;i++)
//     {
//         ll x;
//         cin>>x;
//         v.push_back(x);

//     }
//     int start;
//     cin>>start;
//     Solution Solution;
//     Solution.canReach(v,start);

// }
