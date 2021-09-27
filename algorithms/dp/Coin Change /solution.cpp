#include <bits/stdc++.h>
using namespace std;

int mem[1000];

vector<int> arr;

int numberOfChanges(int idx, int total)
{
    if (total == 0)
        return 1;
    if (total < 0)
        return 0;
    if (idx == arr.size())
        return 0;

    if (mem[idx] != -1)
        return mem[idx];

    return mem[idx] = numberOfChanges(idx + 1, total) + numberOfChanges(idx, total - arr[idx]);
}

int main()
{
    freopen64("input.txt", "r", stdin);
    freopen64("output.txt", "w", stdout);
    arr.clear();
    memset(mem, -1, sizeof mem);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    int amount;
    cin >> amount;
    cout << numberOfChanges(0, amount) << endl;
}