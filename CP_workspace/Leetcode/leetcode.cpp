#include <bits/stdc++.h>
#include <queue>
#include <set>
#include <vector>
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

class Solution {
public:
  set<int> left;
  set<int> right;

  bool increasingTriplet(vector<int> &nums) {

    int lefMin[nums.size()];
    int rightMax[nums.size()];
    memset(lefMin, 0, sizeof lefMin);
    memset(rightMax, 0, sizeof rightMax);
    int mn = inf;
    for (int i = 0; i < nums.size(); i++) {
      mn = min(mn, nums[i]);
      lefMin[i] = mn;
    }
    int mx = -inf;
    for (int i = nums.size() - 1; i >= 0; i--) {
      mx = max(mx, nums[i]);
      rightMax[i] = mx;
    }
    for (int i = 1; i < nums.size() - 1; i++)
      if (nums[i] > lefMin[i - 1] && nums[i] < rightMax[i + 1])
        return true;
    return false;
  }
};

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n;
  cin >> n;
  vector<int> nums;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    nums.push_back(x);
  }
  Solution sol;
  bool ans = sol.increasingTriplet(nums);
  cout << ans << endl;
  // set<int> s;
  // s.insert(10);
  // cout << *s.begin() << endl;
}
