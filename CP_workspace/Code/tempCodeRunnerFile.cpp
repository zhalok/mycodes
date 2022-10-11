#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }

  long long int ans = 0;

  for (int i = 0; i < v.size(); i++) {
    if (v[i] < 0) {
      ans++;
    } else if (v[i] == 0) {
      cout << "0" << endl;
      return;
    }
  }
  cout << ans % 2 << endl;
}

int main() {
  // your code goes here
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
