#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
#include <cstdio>
#include <queue>
#include <string>
#include <vector>
#define inf 100000
using namespace std;

int main() {
  vector<int> v;
  for (int i = 1; i <= 10; i++)
    v.push_back(i);
  cout << v.size() << endl;
  int idx = lower_bound(v.begin(), v.end(), 11) - v.begin();
  cout << idx << endl;
}
