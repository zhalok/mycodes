#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
#define zhalok Zhalok
#define inf 1000000000.0
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
#define sz 10000001
#define ub upper_bound
#define lb lower_bound
#define all(v) v.begin(), v.end()
#define eps 1e-2
#define pi acos(-1.0)

class Convexhull
{

public:
    vpll upper;
    vpll lower;
    set<pll> convexhull;

    pll leftmost;
    pll rightmost;

    int check_sidde(pll p1, pll p2, pll p3)
    {
        ll x1 = p1.first;
        ll y1 = p1.second;
        ll x2 = p2.first;
        ll y2 = p2.second;
        ll x3 = p3.first;
        ll y3 = p3.second;

        ll ans = (x3 - x1) * (y1 - y2) - (y3 - y1) * (x1 - x2);
        if (ans > 0)
            return 1;
        else if (ans < 0)
            return -1;
        else
            return 0;
    }

    int check_rotation(pll a, pll b, pll c)
    {

        ll x1, y1;
        x1 = a.first;
        y1 = a.second;
        ll x2, y2;
        x2 = b.first;
        y2 = b.second;
        ll x3, y3;
        x3 = c.first;
        y3 = c.second;
        ll rotation = (x2 - x1) * (y3 - y2) - (y2 - y1) * (x3 - x2);
        if (rotation > 0)
            return 1;
        else if (rotation == 0)
            return 0;
        else
            return -1;
    }

    void upper_convexhull()
    {

        vector<pii> st;
        st.push_back(upper[0]);
        st.push_back(upper[1]);
        for (int i = 1; i < upper.size(); i++)
        {
            while (st.size() >= 2 && check_rotation(st[st.size() - 2], st[st.size() - 1], lower[i]) > 0)

                st.pop_back();
            st.push_back(upper[i]);
        }

        for (int i = 0; i < st.size(); i++)
            convexhull.insert(st[i]);
    }

    void lower_convexhull()
    {

        vector<pii> st;
        st.push_back(lower[0]);
        st.push_back(lower[1]);

        for (int i = 2; i < lower.size(); i++)
        {

            while (st.size() >= 2 && check_rotation(st[st.size() - 2], st[st.size() - 1], lower[i]) < 0)

                st.pop_back();

            st.push_back(lower[i]);
        }

        for (int i = 0; i < st.size(); i++)
            convexhull.insert(st[i]);
    }

    vector<pll> total_convexhull(vpll points)
    {

        sort(points.begin(), points.end());
        leftmost = points[0];
        rightmost = points[points.size() - 1];

        upper.push_back(leftmost);
        lower.push_back(leftmost);

        for (int i = 0; i < points.size(); i++)
            if (check_sidde(leftmost, rightmost, points[i]) == 1)
                upper.push_back(points[i]);
            else if (check_sidde(leftmost, rightmost, points[i]) == -1)
                lower.push_back(points[i]);

        upper.push_back(rightmost);
        lower.push_back(rightmost);

        lower_convexhull();
        upper_convexhull();

        vpll ans;
        for (auto x : convexhull)
            ans.push_back(x);

        return ans;
    }
};

void solve()
{

    vpll points;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    Convexhull conv;
    vpll ans = conv.total_convexhull(points);
    for (auto x : ans)
        cout << x.first << " " << x.second << endl;
}

int main()
{
    freopen("convexhull_input.txt", "r", stdin);
    freopen("convexhull_output.txt", "w", stdout);

    solve();
}
