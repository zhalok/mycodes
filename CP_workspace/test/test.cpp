#include <bits/stdc++.h>
using namespace std;

vector<int> adjListForMST[1001];
vector<int> costListForMST[1001];
int par[1001];
vector<pair<int, pair<int, int>>> edges;

int findPar(int n)
{
    if (par[n] == n)
        return n;
    return par[n] = findPar(par[n]);
}

void preProcess(int n)
{
    for (int i = 1; i <= n; i++)
        par[i] = i;
}

int main()
{
    edges.clear();
    int n, m;
    cin >> n >> m;
    preProcess(n);
    while (m--)
    {
        int x, y, cost;
        cin >> x >> y >> cost;
        edges.push_back({cost, {x, y}});
    }
    sort(edges.begin(), edges.end());
    int totalMinCost = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int cost = edges[i].first;
        int node1 = edges[i].second.first;
        int node2 = edges[i].second.second;
        int parNode1 = findPar(node1);
        int parNode2 = findPar(node2);
        if (parNode1 != parNode2)
        {
            par[parNode2] = parNode1;
            totalMinCost += cost;
            adjListForMST[node1].push_back(node2);
            adjListForMST[node2].push_back(node1);
            costListForMST[node1].push_back(cost);
            costListForMST[node2].push_back(cost);
        }
    }

    cout << totalMinCost << endl;
}