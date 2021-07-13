#include <bits/stdc++.h>
#include <map>
#include <iostream>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
#define zhalok Zhalok
#define inf 1000000001
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
#define eps 1e-9
#define pi acos(-1.0)

void solve()
{
    int n;
    cin >> n;
    vector<pair<pii, int>> v;
    for (int i = 0; i < n; i++)
    {
        int deadline;
        int profit;
        cin >> deadline >> profit;
        v.push_back({{profit, deadline}, i});
    }

    sort(all(v), greater<pair<pii, int>>());

    vi ans[n + 1];
    memset(ans, 0, sizeof ans);
    for (int i = 0; i < v.size(); i++)
    {
        int deadline = v[i].first.second;
        int profit = v[i].first.first;
        int id = v[i].second;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    solve();
}