/*“In the name of Allah, The Most Gracious and The Most Merciful“*/
#include <bits/stdc++.h>
#include <map>
#include <iostream>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
#define zhalok zhalok
#define inf 2000000000
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
#define sz 400001
#define ub upper_bound
#define lb lower_bound
#define all(v) v.begin(), v.end()
#define eps 1e-6
#define pi acos(-1.0)

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    ll mxedge = n * (n - 1);
    mxedge /= 2;
    if (m > mxedge)
    {
        cout << "NO" << endl;
        return;
    }
    if (m == mxedge)
    {
        if (k > 2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else
    {
        if (k > 3)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
        solve();
}