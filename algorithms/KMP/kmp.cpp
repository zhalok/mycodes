#include <bits/stdc++.h>
using namespace std;
using namespace std;
#define zhalok Zhalok
#define inf 1000
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

int pref[1000];

// the main idea of finding the lps array or the pref array is that
// lets say that u are at position i and u want to calculate the pref array value of position i
// then lets see that can we find a proper prefix of substring 0 to i-1 which is also a proper suffix
// if that is so then lets say the len of that proper prefix is x
// now if s[x]==s[i] occurs that means what ? that means now the character at position x is equal to the character at position i the prefix 0 to x-1 is also a suffix
// now that means we have a prefix of len x+1 from 0 to x which is also a suffix right ?

void make_pref(string s)
{
    memset(pref, 0, sizeof pref);

    for (int i = 1; i < s.size(); i++)
    {
        int j = pref[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pref[j - 1];

        if (s[i] == s[j])
            pref[i] = j + 1;
    }
}

// while matching if we find a mismatch s[i]!=s[j]
// but we have matched up to j-1 right ?
// so if i have a prefix which is also a suffix i can start checking
// from the next value of that prefix right ?
// we can go to that value with the pref array at index j-1
// if we are at index j = 0 and s[i]!=s[j] that means there is no chance
// of matching from index i so we shift i to i+1

bool match(string s, string t)
{
    make_pref(t);
    int i = 0;
    int j = 0;
    while (i < s.size())
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {

            if (j == t.size())
                return true;

            if (j == 0)
                i++;
            else
                j = pref[j - 1];
        }
    }
    return false;
}

void solve()
{
    string s, t;
    cin >> s >> t;

    if (match(s, t))
        cout << "yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve();
}
