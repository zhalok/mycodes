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

class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        map<char, int> mp;
        ll ans[s.size()];
        memset(ans, 0, sizeof ans);

        for (int i = 0; i < s.size(); i++)
            mp[s[i]] = -1;

        for (int i = 0; i < s.size(); i++)
        {
            if (mp[s[i]] != -1)
                ans[i] = ans[mp[s[i]]] + (i - mp[s[i]] - 1);
            mp[s[i]] = i;
        }

        ll total = 0;
        for (auto x : ans)
            total += x;
        return total;
    }
};

// int main()
// {
//     // cout<<"HEllo world"<<endl;
//     //gu
//     int m;
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     int n;
//     cin>>n;
//     vi v;
//     for(int i=0;i<n;i++)
//     {
//         int x;
//         cin>>x;
//         v.push_back(x);

//     }

//     for(auto x: v)cout<<x<<endl;

//     // Solution solution;

//     // string s;
//     // vector<string>v;

//     // cin>>s;
//     // int n;
//     // cin>>n;
//     // for(int i=0;i<n;i++)
//     // {
//     //     string s;
//     //     cin>>s;
//     //     v.push_back(s);
//     // }

//     // vi ans = solution.findSubstring(s,v);
//     // for(auto x:ans) cout<<x<<" ";
//     // cout<<endl;

// }
