#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <math.h>
#include <ostream>
#include <queue>
#include <tuple>
#include <unistd.h>
#include <valarray>
#include <vector>
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
#define sz 5001
#define ub upper_bound
#define lb lower_bound
#define all(v) v.begin(), v.end()
#define eps 1e-8
#define pi acos(-1.0)

ll maxx(ll a, ll b) { return (a > b) ? a : b; }

ll minn(ll a, ll b) { return (a < b) ? a : b; }

ll cill(ll a, ll b) {
  if (a % b == 0)
    return a / b;
  else
    return a / b + 1;
}

vector<int> adj[200001];
bool visited[200001];

void preprocessing(int n) {
  for (int i = 0; i <= 2 * n; i++)
    adj[i].clear();
}

void dfs(int node) {
  visited[node] = true;
  for (int i = 0; i < adj[node].size(); i++) {
    int cur_node = adj[node][i];
    if (visited[cur_node] == false)
      dfs(cur_node);
  }
}

int noc(int n) {
  memset(visited, false, sizeof visited);
  int ans = 0;
  for (int i = 0; i < 2 * n; i++)
    if (visited[i] == false) {
      ans++;
      dfs(i);
    }
  return ans;
}

void solve(int t) {
  int n;
  cin >> n;
  int arr[n + 1];
  for (int i = 1; i <= n; i++)
    cin >> arr[i];
  int m;
  cin >> m;
  int brr[m + 1];
  for (int i = 1; i <= m; i++)
    cin >> brr[i];
  vector<pair<int, pii>> v;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int gap = abs(arr[i] - brr[j]);
      v.push_back({gap, {i, j}});
    }
  sort(all(v));
  bool visited1[n + 1];
  bool visited2[m + 1];
  memset(visited1, 0, sizeof visited1);
  memset(visited2, 0, sizeof visited2);
  int ans = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i].first <= 1 && visited1[v[i].second.first] == false &&
        visited2[v[i].second.second] == false) {
      visited1[v[i].second.first] = true;
      visited2[v[i].second.second] = true;
      ans++;
    }
  }
  memset(visited1, false, sizeof(visited1));
  memset(visited2, false, sizeof visited2);
  int ans1 = 0;
  for (int i = v.size() - 1; i >= 0; i--) {
    if (v[i].first <= 1 && visited1[v[i].second.first] == false &&
        visited2[v[i].second.second] == false) {
      visited1[v[i].second.first] = true;
      visited2[v[i].second.second] = true;
      ans1++;
    }
  }
  ans = maxx(ans, ans1);
  cout << ans << endl;
}
int main() {
  // freopen64("input.txt", "r", stdin);
  // freopen64("output.txt", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // cout << sum(1, 2) << endl;
  int T;
  // cin >> T;
  T = 1;
  // scanf("%d", &T);
  for (int t = 1; t <= T; t++)
    solve(t);
}