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

int find_max(vpii v)
{
    int mx = INT_MIN;
    for (auto x : v)
        mx = max(mx, x.first);
    return mx;
}

void stableSort(vpii &arr)
{
    // sorting on the first element
    int mx = find_max(arr);
    vpii ans(arr.size());
    int counter[mx + 1];
    memset(counter, 0, sizeof counter);

    for (auto x : arr)
        counter[x.first]++;

    for (int i = 1; i <= mx; i++)
        counter[i] += counter[i - 1];

    // traversing forward will give us unstable sorting
    // traversing backward will give us stables sorting

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        ans[counter[arr[i].first] - 1] = arr[i];
        counter[arr[i].first]--;
    }

    for (int i = 0; i < ans.size(); i++)
        arr[i] = ans[i];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vpii v;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    stableSort(v);

    for (auto x : v)
        cout << x.first << " " << x.second << endl;

    cout << endl;

    return 0;
}
