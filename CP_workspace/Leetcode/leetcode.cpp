#include <bits/stdc++.h>
#include <string>
#include <system_error>
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
#define sz 10001
#define ub upper_bound
#define lb lower_bound
#define all(v) v.begin(), v.end()
#define eps 1e-8
#define pi acos(-1.0)

class Solution {
public:
  bool isAnagram(string s, string t) {
    sort(all(s));
    sort(all(t));
    if (s.size() != t.size())
      return false;
    for (int i = 0; i < s.size(); i++)
      if (s[i] != t[i])
        return false;
    return true;
  }
};
int main() {

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  // int n;
  // cin >> n;
  // vector<vector<int>> v;
  // for (int i = 0; i < n; i++) {
  //   vector<int> temp;
  //   for (int j = 0; j < n; j++) {
  //     ll x;
  //     cin >> x;
  //     temp.push_back(x);
  //   }
  //   v.push_back(temp);
  // }
  // Solution sol;
  // sol.setZeroes(v);
}
