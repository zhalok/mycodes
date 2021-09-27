#include <bits/stdc++.h>
using namespace std;

int mem[1000];

vector<int> arr;

int LIS(int idx)
{
    if (idx == arr.size())
        return 0;
    if (mem[idx] != -1)
        return mem[idx];

    int ans = 0;
    for (int i = idx + 1; i < arr.size(); i++)
    {
        if (arr[i] > arr[idx])
        {
            ans = max(ans, 1 + LIS(i));
        }
    }

    mem[idx] = ans;
    return ans;
}

int main()
{
    freopen64("input.txt", "r", stdin);
    freopen64("output.txt", "w", stdout);

    int n;
    cin >> n;

    arr.clear();
    memset(mem, -1, sizeof mem);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
        ans = max(ans, 1 + LIS(i));
    cout << ans << endl;
}