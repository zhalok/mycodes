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

string str;
int max_cap;

class Solution
{
public:
    bool isTrue(int len)
    {
        int i = 0;
        int j = len - 1;
        int ts = 0;
        int ks = 0;

        for (int i = 0; i < len; i++)
            if (str[i] == 'T')
                ts++;
            else
                ks++;

        if (min(ts, ks) <= max_cap)
            return true;

        while (j < str.size())
        {
            if (j == str.size() - 1)
                break;
            if (str[i] == 'T')
                ts--;
            else if (str[i] == 'F')
                ks--;
            i++;
            j++;
            if (str[j] == 'T')
                ts++;
            else if (str[j] == 'F')
                ks++;

            if (min(ts, ks) <= max_cap)
                return true;
        }

        return false;
    }

    int maxConsecutiveAnswers(string answerKey, int k)
    {
        str = answerKey;
        max_cap = k;

        int lo = 0;
        int hi = answerKey.size();
        int ans = 0;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (isTrue(mid))
            {
                lo = mid + 1;
                ans = max(ans, mid);
            }
            else
                hi = mid - 1;
        }
        return ans;
    }
};

// int main()
// {

//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);

//     // string str;
//     // int k;
//     cin >> str;
//     cin >> max_cap;

//     Solution sol;
//     cout << sol.maxConsecutiveAnswers(str, max_cap);
// }
