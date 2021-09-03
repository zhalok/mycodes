#include <bits/stdc++.h>
#include <map>
#include <iostream>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
#define inf 2000000000
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

void dijkstra(int source, int sink)
{
    pq.push({-costs[source], source});

    while (pq.size())
    {
        int cur = pq.top().second;
        pq.pop();
        for (int i = 0; i < adj[cur].size(); i++)
        {
            int newNode = adj[cur][i];
            if (cur + w[cur][i] < costs[newNode])
            {
                par[newNode] = cur;
                costs[newNode] = cur + w[cur][i];
                pq.push({-costs[newNode], newNode});
            }
        }
    }

    int cur_node = sink;
    while (cur_node != -1)
    {
        shortestPath.push_back(cur_node);
        cur_node = par[cur_node];
    }

    reverse(all(shortestPath));
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

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}