#include <bits/stdc++.h>
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

int grid[9][9];
int n;

bool check(int val, int row, int col)
{
    for (int i = 0; i < n; i++)
        if (grid[row][i] == val)
            return false;

    for (int i = 0; i < n; i++)
        if (grid[i][col] == val)
            return false;

    int x = row / 3;
    int y = col / 3;

    for (int i = 3 * x; i < 3 * x + 3; i++)
        for (int j = 3 * y; j < 3 * y + 3; j++)
            if (grid[i][j] == val)
                return false;

    return true;
}

bool solve(int row, int col)
{
    if (col == n)
    {
        if (row == n - 1)
            return true;
        else
        {
            return solve(row + 1, 0);
        }
    }

    if (grid[row][col] == 0)
    {
        for (int k = 1; k <= 9; k++)
        {
            if (check(k, row, col))
            {
                grid[row][col] = k;
                bool ans = solve(row, col + 1);
                if (ans)
                    return ans;
            }
        }
        grid[row][col] = 0;
    }
    else
        return solve(row, col + 1);
    return false;
}

class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        n = board.size();
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (board[i][j] == '.')
                    grid[i][j] = 0;
                else
                    grid[i][j] = board[i][j] - '0';
        solve(0, 0);
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                board[i][j] = grid[i][j] + '0';
    }
};

// int main()
// {

//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);

//     vector<vector<char>> v;
//     for (int i = 0; i < 9; i++)
//     {
//         vector<char> temp;
//         for (int j = 0; j < 9; j++)
//         {
//             char c;
//             cin >> c;
//             temp.push_back(c);
//         }
//         v.push_back(temp);
//     }

//     Solution sol;
//     sol.solveSudoku(v);
//     for (int i = 0; i < 9; i++)
//     {
//         for (int j = 0; j < 9; j++)
//             cout << grid[i][j] << " ";
//         cout << endl;
//     }
// }
