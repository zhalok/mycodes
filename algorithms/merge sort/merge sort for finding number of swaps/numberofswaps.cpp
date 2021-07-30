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

ll minn(ll a, ll b)
{
    return a < b ? a : b;
}

ll maxx(ll a, ll b)
{
    return a > b ? a : b;
}

ll cill(ll a, ll b)
{
    if (a % b == 0)
        return a / b;
    return a / b + 1;
}
vll v;
ll cnt;

void merge(int lo, int hi)
{
    int mid = (lo + hi) / 2;
    int i = lo;
    int j = mid + 1;
    vll vv;
    while (i <= mid && j <= hi)
    {
        if (v[i] <= v[j])
            vv.push_back(v[i++]);
        else
        {
            ll temp_cnt = (mid - i + 1);
            cnt += temp_cnt;
            vv.push_back(v[j++]);
        }
    }

    while (i <= mid)
        vv.push_back(v[i++]);
    while (j <= hi)
        vv.push_back(v[j++]);

    for (int i = 0, x = lo; i < vv.size() && x <= hi; i++, x++)
        v[x] = vv[i];
}

void mergesort(int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    mergesort(l, mid);
    mergesort(mid + 1, r);
    merge(l, r);
}

void solve()
{
    int n;
    cin >> n;
    v.clear();
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v.push_back(x);
    }

        mergesort(0, v.size() - 1);
    cout << cnt << endl;
    // for (int i = 0; i < n; i++)
    //     cout << v[i] << " ";
    // cout << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve();
}