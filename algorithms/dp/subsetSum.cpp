#include <bits/stdc++.h>
using namespace std;
int mem[101][101];

int arr[101];

int n;

bool dp(int idx, int target)
{

    if (target < 0)
        return false;
    if (target == 0)
        return true;
    if (idx == n)
        return false;
    if (mem[idx][target] != -1)
        return mem[idx][target];
    return mem[idx][target] = dp(idx + 1, target - arr[idx]) | dp(idx + 1, target);
}

int main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    memset(mem, -1, sizeof mem);
    int target;
    cin >> target;
    cout << dp(0, target) << endl;
}
