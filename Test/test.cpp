#include <bits/stdc++.h>
using namespace std;
int dp[6][8000];
int cents[6] = {0, 50, 25, 10, 5, 1};
int call(int cent, int money)
{
    if (money == 0)
        return 1;
    if (money < 0)
        return 0;
    if (cent == 0)
        return 0;
    if (dp[cent][money] != -1)
        return dp[cent][money];
    int x = call(cent - 1, money);
    int y = call(cent, money - cents[cent]);
    dp[cent][money] = x + y;
    return x + y;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    while (~scanf("%d", &n))
    {
        memset(dp, -1, sizeof dp);
        cout << call(5, n) << endl;
    }
}