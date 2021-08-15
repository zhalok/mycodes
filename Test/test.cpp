#include <bits/stdc++.h>
#include <map>
#include <iostream>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
#define zhalok zhalok
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

ll minn(ll a, ll b)
{
    return a < b ? a : b;
}

ll maxx(ll a, ll b)
{
    return a > b ? a : b;
}

double maxx(double a, double b)
{
    return ((a - b > eps)) ? a : b;
}

ll cill(ll a, ll b)
{
    if (a % b == 0)
        return a / b;
    return a / b + 1;
}

int movex[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int movey[8] = {0, 0, 1, -1, 1, 1, -1, -1};

pii solve_eqn(ll a1, ll b1, ll a2, ll b2, ll c1, ll c2)
{

    ll del = a1 * b2 - b1 * a2;
    ll delx = c1 * b2 - c2 * b1;
    ll dely = a1 * c2 - a2 * c1;

    long double x, y;
    if (delx == 0)
        x = 0.0;
    else
        x = (1.0 * delx) / del;

    if (dely == 0)
        y = 0.0;
    else
        y = (1.0 * dely) / del;
    //  cout<<fixed<<setprecision(10)<<x<<" "<<y<<endl;

    return {x, y};
}

double find_dis(double x1, double y1, double x2, double y2)
{
    double ans = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    return ans;
    return sqrt(ans);
}

ll mod_exp(ll a, ll n, ll mod)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
    {
        ll temp = mod_exp(a, n / 2, mod);
        return (temp % mod * temp % mod) % mod;
    }
    else
    {
        ll temp1 = a;
        ll temp2 = mod_exp(a, n - 1, mod);
        return (temp1 % mod * temp2 % mod) % mod;
    }
}

ll mod_inv(ll n, ll mod)
{
    return mod_exp(n, mod - 2, mod);
}

ll abss(ll a)
{
    if (a >= 0)
        return a;
    else
        return -1 * (a);
}

long double get_angle(pii a, pii b, pii c)
{
    int x1 = a.first;
    int y1 = a.second;
    int x2 = b.first;
    int y2 = b.second;
    int x3 = c.first;
    int y3 = c.second;
    long double len1 = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    long double len2 = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    long double val = ((x1 - x2) * (x3 - x2) + (y1 - y2) * (y3 - y2)) / (len1 * len2);
    return acos(val);
}

long double find_point_dis(pii point1, pii point2)
{
    long double temp_ans;
    temp_ans = ((point1.first - point2.first) * (point1.first - point2.first));
    temp_ans += ((point1.second - point2.second) * (point1.second - point2.second));
    return sqrt(temp_ans);
}

int check_sidde(pii p1, pii p2, pii p3)
{
    int x1 = p1.first;
    int y1 = p1.second;
    int x2 = p2.first;
    int y2 = p2.second;
    int x3 = p3.first;
    int y3 = p3.second;

    ll ans = (x3 - x1) * (y1 - y2) - (y3 - y1) * (x1 - x2);
    if (ans >= 0)
        return 1;
    else
        return -1;
}

ll cnt_div(ll n, ll k)
{
    ll cnt = 0;
    while (n % k == 0)
    {
        cnt++;
        n /= k;
    }
    return cnt;
}

ll gcd(ll a, ll b)
{
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    ll g = gcd(a, b);
    return (a * b) / g;
}

int extended_gcd(int a, int b, int &x, int &y)
{

    if (b == 0)
    {
        cout << "BAse case" << endl;
        x = 1;
        y = 0;
        return a;
    }

    cout << "not base case" << endl;
    int x1, y1;
    int d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll get_digit_sum(ll n)
{
    ll sum = 0;
    while (n)
    {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

ll count_digits(ll n)
{
    ll ans = 0;
    while (n)
    {
        ans++;
        n /= 10;
    }
    return ans;
}

vll fact;

void factorial_precalculation()
{
    fact.push_back(1);
    ll factor = 1;
    for (int i = 1; i <= 200000; i++)
    {
        factor *= i;
        factor %= MOD;
        fact.push_back(factor);
    }
}

bool primechk[sz];

vector<int> primes;

void seive(ll n)
{

    for (ll i = 2; i * i <= n; i++)
        if (primechk[i] == false)
            for (ll j = i * i; j <= n; j += i)
                primechk[j] = true;

    for (int i = 2; i <= n; i++)
        if (primechk[i] == false)
            primes.push_back(i);
}

ll count_primes(ll x, ll p)
{
    ll cnt = 0;
    while (x % p == 0)
    {
        cnt++;
        x /= p;
    }

    return cnt;
}

vll factorization(ll n)
{
    vll used_primes;

    ll temp_n = n;
    for (int i = 2; i * i <= temp_n; i++)
        while (n % i == 0)
        {
            used_primes.push_back(i);

            n /= i;
        }

    if (n > 1)
        used_primes.push_back(n);

    return used_primes;
}

int calculate_digits(ll n)
{

    ll cnt = 0;
    while (n)
    {
        n /= 10;
        cnt++;
    }

    return cnt;
}

ll digit_to_num(vll v)
{
    ll sum = 0;
    for (auto x : v)
    {
        sum *= 10;
        sum += x;
    }
    return sum;
}

vi adj[sz];
bool visited[sz];

void dfs(int node)
{
    visited[node] = true;
    loop(i, 0, adj[node].size())
    {
        int cur = adj[node][i];
        if (visited[cur] == false)
            dfs(cur);
    }
}

int get_ans(vi v, int n)
{
    int left_idx;
    int right_idx;
    for (int i = 0; i < v.size(); i++)

        if (v[i] == n)
        {
            left_idx = i;
            break;
        }

    for (int i = v.size() - 1; i >= 0; i--)
        if (v[i] == n)
        {
            right_idx = i;
            break;
        }

    int cnt1 = left_idx + 1;
    int cnt2 = n - right_idx;
    if (cnt1 < cnt2)
        return left_idx;
    else
        return right_idx;
}

int pref[1000];

void make_pref(string s)
{
    memset(pref, 0, sizeof pref);

    for (int i = 1; i < s.size(); i++)
    {
        int j = pref[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pref[j - 1];

        if (s[i] == s[j])
            pref[i] = j + 1;
    }
}

bool match(string s, string t)
{
    make_pref(t);
    int i = 0;
    int j = 0;
    while (i < s.size())
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {

            if (j == t.size())
                return true;

            if (j == 0)
                i++;
            else
                j = pref[j - 1];
        }
    }

    if (j == t.size())
        return true;

    return false;
}

// bool match(string s, string t)
// {
// 	int i = 0;
// 	int j = t.size() - 1;
// 	while (j < s.size())
// 	{
// 		string temp;
// 		for (int x = i; x <= j; x++)
// 			temp += s[x];
// 		if (temp == t)
// 			return true;
// 		i++;
// 		j++;
// 	}

// 	return false;
// }

vll factorials;

void preCalculation(ll n, ll mod)
{

    ll fact = 1;
    factorials.push_back(fact);

    for (int i = 1; i <= n; i++)
    {
        fact *= i;
        fact %= mod;
        factorials.push_back(fact);
    }
}

ll process(ll n, ll k)
{

    ll ans1 = factorials[n];
    ll ans2 = factorials[k];
    ll ans3 = factorials[n - k];
    ll ans = (ans1 % MOD) * mod_inv(ans2, MOD) * mod_inv(ans3, MOD);
    return ans % MOD;
}

ll dp[200001][2];
int n, k;
ll comb, pown;

ll get_ans(int idx, bool flag)
{

    if (idx == k)
        return 1;
    if (dp[idx][flag] != -1)
        return dp[idx][flag];
    ll ans = 0;
    if (flag)
        ans = get_ans(idx + 1, true) % MOD + ((pown - 1) % MOD * get_ans(idx + 1, false) % MOD) % MOD;
    else
        ans = get_ans(idx + 1, true) % MOD + ((comb - 1) % MOD * get_ans(idx + 1, false) % MOD) % MOD;

    return dp[idx][flag] = ans % MOD;
}

void solve()
{

    int n;
    cin >> n;
    list<int> li;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        li.push_front(x);
    }

    for (auto x : li)
        cout << x << " ";
    cout << endl;
}

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;

    // cin >> T;
    // for (int i = 1; i <= T; i++)
    solve();
}