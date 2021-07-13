#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define sz 2000009
#define mod 1000000007
#define inf 1e10 + 1e15
#define f first
#define s second
#define pa pair<ll, ll>
#define eps 1e-9
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll arr[sz], brr[sz];
ll a123;
double an;
void solve(double c, double m, double p, double v, ll ca, double cr)
{
    //printf("%f %f %f %f\n",c,m,p,v);

    double ans1 = p;
    an += (p * cr * ca);
    double ans2, ans3;
    if (abs(c) <= eps)
        ans2 = 0.0;
    else
    {

        //  printf("%f\n",c);
        double m1 = m, p1 = p, c1 = max(0.0, c - v);
        // m1+=min(c,v)/2.0;
        p1 += min(c, v) / 2.0;
        if (abs(m1) <= eps)
            p1 += min(c, v) / 2.0;
        else
            m1 += min(c, v) / 2.0;
        // printf("%f %f %f\n",c1,m1,p1);
        solve(c1, m1, p1, v, ca + 1, cr * c);
    }
    if (abs(m) <= (eps))
        ans3 = 0.0;
    else
    {

        double c1 = c, p1 = p, m1 = max(0.0, m - v);
        // c1+=min(m,v)/2.0;
        p1 += min(m, v) / 2.0;
        if (abs(c1) <= eps)
            p1 += min(m, v) / 2.0;
        else
            c1 += min(m, v) / 2.0;
        solve(c1, m1, p1, v, ca + 1, cr * m);
    }
    //printf("%f %f %f\n",ans1,ans2,ans3);
}
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test_case = 207;
    scanf("%d", &test_case);
    for (int cs = 1; cs <= test_case; cs++)
    {
        double c, m, p, v;
        scanf("%lf %lf %lf %lf", &c, &m, &p, &v);
        an = 0.0;
        solve(c, m, p, v, 1, 1.0);
        // printf("%f\n",solve(c,m,p,v));
        printf("%0.10f\n", an);
    }
    return 0;
}