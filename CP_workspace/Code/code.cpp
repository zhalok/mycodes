#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <iterator>
#include <ostream>
#include <queue>
#include <tuple>
#include <unistd.h>
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

// int vect_to_num(vi v) {
//   int sum = 0;
//   for (int i = 0; i < v.size(); i++) {
//     sum *= 10;
//     sum += v[i];
//   }
//   return sum;
// }

// vi num_to_vect(int n) {
//   vector<int> v;
//   while (n) {
//     v.push_back(n % 10);
//     n /= 10;
//   }
//   reverse(all(v));
//   return v;
// }

// int handleExceptionCase(vector<int> v) {
//   int num = vect_to_num(v);
//   int ans[v.size()];
//   memset(ans, 0, sizeof ans);
//   ans[v.size() - 1] = ((11 - v[v.size() - 1]) % 10);
//   num += ((11 - v[v.size() - 1]) % 10);
//   vi v1;
//   for (int i = 0; i < v.size() + 1; i++) {
//     v1.push_back(num % 10);
//     num /= 10;
//   }
//   reverse(all(v1));
//   if (v1[0] != v1[v.size() - 1]) {
//     v1[0] = 1;
//     v1[1] = 0;
//     ans[0] = 1;
//   }
//   int i = 1;
//   int j = v.size() - 2;
//   while (i <= j) {
//     if (v1[i] < v1[j]) {
//       ans[i - 1] += (v1[j] - v1[i]);
//       ans[j] = 0;
//     } else {
//       ans[j] = (v1[i] - v1[j]);
//       ans[i] = 0;
//     }
//     i++;
//     j--;
//   }
//   int final_ans = 0;
//   for (int i = 0; i < v.size(); i++) {
//     final_ans *= 10;
//     final_ans += ans[i];
//   }
//   return final_ans;
// }

// vll v;
// vll pref;
// ll mem[200001];
// ll val[200001];

// int n;
// // int calc_cost(int d) {
// //   map<int, bool> mp;
// //   for (int i = 6; i >= 1; i--) {
// //     if (mp[i] == false)
// //   }
// // }
// ll factorial[100001];

// void preProcess() {
//   ll fact = 1;
//   factorial[0] = 1;
//   for (int i = 1; i <= 100000; i++) {
//     factorial[i] = factorial[i - 1] * i;
//     factorial[i] %= MOD;
//   }
// }

vll v;
ll arr[5001];
int n;
ll segment_counter[5001][5001];
bool isPossible(int left, int right) {
  return ((right - left) + 1) % 2 == 0 &&
                 segment_counter[left][right] <= (n / 2)
             ? true
             : false;
}

ll dp(int idx) {
  if (idx == v.size() - 1) {
    return isPossible(v[idx] + 1, n);
  }
  ll ans = 0;
  bool flag = false;
  for (int i = idx + 1; i < v.size(); i++)

    if (isPossible(v[idx] + 1, v[i] - 1)) {
      ll temp_ans = 1 + dp(i);
      ans = maxx(ans, temp_ans);
    }

  return ans;
}

void solve(int t) {
  int n;
  cin >> n;
  int arr[n + 1];
  for (int i = 1; i <= n; i++)
    cin >> arr[i];
  int prev[n + 1];
  int ans[n + 1];
  memset(ans, 0, sizeof ans);
  memset(prev, 0, sizeof prev);
  for (int i = 1; i <= n; i++) {
    // cout << arr[i] << " " << prev[arr[i]] << " " << i << endl;
    if (prev[arr[i]] % 2 != i % 2 || prev[arr[i]] == 0) {
      ans[arr[i]]++;
      prev[arr[i]] = i;
    }
  }
  for (int i = 1; i <= n; i++)
    cout << ans[i] << " ";
  cout << endl;
}
int main() {
  freopen64("input.txt", "r", stdin);
  freopen64("output.txt", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // cout << sum(1, 2) << endl;
  int T;
  cin >> T;
  // T = 1;
  // scanf("%d", &T);
  for (int t = 1; t <= T; t++)
    solve(t);
}