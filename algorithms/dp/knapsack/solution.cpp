#include <bits/stdc++.h>
using namespace std;

int mem[1000][1000];

vector<int> val;
vector<int> weights;
int n;

int knapsack(int idx, int cap)
{
    if (idx == n)
        return 0;

    // if (mem[idx][cap] != -1)
    //     return mem[idx][cap];

    int ans = 0;
    if (cap - weights[idx] >= 0)
        ans = max(ans, val[idx] + knapsack(idx + 1, cap - weights[idx]));
    ans = max(ans, knapsack(idx + 1, cap));
    return mem[idx][cap] = ans;
}

int main()
{
    freopen64("input.txt", "r", stdin);
    freopen64("output.txt", "w", stdout);

    cin >> n;
    val.clear();
    weights.clear();
    memset(mem, -1, sizeof mem);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        val.push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        weights.push_back(x);
    }

    int cap;
    cin >> cap;
    cout << knapsack(0, cap) << endl;
}