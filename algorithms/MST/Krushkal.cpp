#include <bits/stdc++.h>
using namespace std;

int par[10001];

vector<pair<int, pair<int, int>>> edges;
vector<pair<int, int>> mst_edges;

int findSet(int n)
{
    if (par[n] == n)
        return n;
    return par[n] = findSet(par[n]);
}

void unionSet(int rootX, int rootY)
{
    par[rootY] = rootX;
}

void makeSet(int m)
{
    while (m--)
    {
        int x, y, c;
        cin >> x >> y >> c;
        edges.push_back({c, {x, y}});
    }
}

void preProcess(int n)
{
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
    }
    edges.clear();
    mst_edges.clear();
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    preProcess(n);

    makeSet(m);

    sort(edges.begin(), edges.end());

    int totalCost = 0;

    for (int i = 0; i < edges.size(); i++)
    {

        int x = edges[i].second.first;
        int y = edges[i].second.second;
        int c = edges[i].first;

        int rootX = findSet(x);
        int rootY = findSet(y);
        if (rootX != rootY)
        {
            unionSet(rootX, rootY);
            totalCost += c;
            mst_edges.push_back({x, y});
        }
    }
    cout << "MST edges:" << endl;
    for (int i = 0; i < mst_edges.size(); i++)
        cout << mst_edges[i].first << " " << mst_edges[i].second << endl;
    cout << "Total cost of MST: " << totalCost << endl;
}