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

int lps[301];

vector<string> v1;
vector<string> v2;

void make_lps(string s)
{
    memset(lps, 0, sizeof lps);

    for (int i = 1; i < s.size(); i++)
    {

        int j = lps[i - 1];
        while (j > 0 && s[i] != s[j])
            j = lps[j - 1];

        if (s[i] == s[j])
            lps[i] = j + 1;
    }
}

map<int, int> mp;

void kmp_match(string s, string t)
{
    make_lps(t);

    int i = 0;
    int j = 0;
    while (i < s.size())
    {

        if (j == t.size())
        {
            mp[i - j]++;
            j = lps[j - 1];
        }

        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
    }

    if (j == t.size())
        mp[i - j]++;
}

void solve()
{
    int n1, n2;
    cin >> n1 >> n2;
    for (int i = 0; i < n1; i++)
    {
        string s;
        cin >> s;
        v1.push_back(s);
    }

    int m1, m2;
    cin >> m1 >> m2;
    for (int i = 0; i < m1; i++)
    {
        string s;
        cin >> s;
        v2.push_back(s);
    }

    vpii ans;

    for (int i = 0; i + n1 <= m1; i++)
    {

        mp.clear();
        for (int j = 0; j < n1; j++)
            kmp_match(v2[i + j], v1[j]);

        for (int j = 0; j < m2; j++)
            if (mp[j] == n1)
                ans.push_back({i + 1, j + 1});
    }

    if (ans.size() == 0)
    {
        cout << "NO MATCH FOUND..." << endl;
        return;
    }

    for (int i = 0; i < ans.size(); i++)
        cout << "(" << ans[i].first << "," << ans[i].second << ")" << endl;
}

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}