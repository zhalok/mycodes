#include <bits/stdc++.h>
#include <map>
#include <iostream>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
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
#define sz 400001
#define ub upper_bound
#define lb lower_bound
#define all(v) v.begin(), v.end()
#define eps 1e-6
#define pi acos(-1.0)

priority_queue<pii> pq;
vi shortestPath;

vi adj[sz];
vi w[sz];
int costs[sz];
int par[sz];

void dijkstra(int source)
{
    costs[source] = 0;
    pq.push({-costs[source], source});

    while (pq.size())
    {
        int cur = pq.top().second;
        pq.pop();
        for (int i = 0; i < adj[cur].size(); i++)
        {
            int newNode = adj[cur][i];
            if (costs[cur] + w[cur][i] < costs[newNode])
            {
                par[newNode] = cur;
                costs[newNode] = costs[cur] + w[cur][i];
                pq.push({-costs[newNode], newNode});
            }
        }
    }
}

void preProcess(int n)
{

    for (int i = 0; i <= n; i++)
    {
        adj[i].clear();
        w[i].clear();
        costs[i] = inf;
        par[i] = -1;
    }
}

void find_sortestPath(int start, int end)
{
    shortestPath.clear();
    int cur = end;
    while (cur != -1)
    {
        shortestPath.push_back(cur);
        cur = par[cur];
    }

    if (costs[end] == inf)
    {
        cout << "NO path" << endl;
        return;
    }

    reverse(all(shortestPath));
    for (auto x : shortestPath)
        cout << x << " ";
    cout << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    preProcess(n);
    while (m--)
    {
        int x, y, c;
        cin >> x >> y >> c;
        adj[x].push_back(y);
        w[x].push_back(c);
    }

    dijkstra(1);
    for (int i = 2; i <= 5; i++)
    {
        shortestPath.clear();
        int cur = i;
        while (cur != -1)
        {
            shortestPath.push_back(cur);
            cur = par[cur];
        }
        reverse(all(shortestPath));
        for (auto x : shortestPath)
            cout << x << " ";
        cout << endl;
    }
}