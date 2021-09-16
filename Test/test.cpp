#include <bits/stdc++.h>
using namespace std;

int movex[4] = {0, 0, 1, -1};
int movey[4] = {1, -1, 0, 0};

int grid[10][10];
bool visited[10][10];

bool checkReachability(pair<int, int> source, pair<int, int> sink)
{
    memset(visited, false, sizeof visited);
    queue<pair<int, int>> q;
    q.push(source);
    visited[source.first][source.second] = true;
    while (q.size())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = cur.first + movex[i];
            int y = cur.second + movey[i];
            if (grid[x][y] == 0 && visited[x][y] == false)
            {
                visited[x][y] = true;
                q.push({x, y});
            }
        }
    }

    if (visited[sink.first][sink.second])
        return true;

    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char grid[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int x;
            cin >> x;
            if (x == 1)
                grid[i][j] = '*';
            else if (x == 0)
                grid[i][j] = '.';
            else if (x == 2)
                grid[i][j] = 'S';
            else if (x == 3)
                grid[i][j] = 'E';
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}