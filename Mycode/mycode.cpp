#include <bits/stdc++.h>
#include <map>
#include <iostream>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
#define zhalok Zhalok
#define inf 100001
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
#define eps 1e-9
#define pi acos(-1.0)

ll minn(ll a, ll b)
{
	return a < b ? a : b;
}

ll maxx(ll a, ll b)
{
	return a > b ? a : b;
}

ll cill(ll a, ll b)
{
	if (a % b == 0)
		return a / b;
	return a / b + 1;
}

int movex[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int movey[8] = {0, 0, 1, -1, 1, 1, -1, -1};

/*

void solve_eqn(ll a1,ll b1,ll a2,ll b2,ll c1,ll c2)
{
	 
     ll del=a1*b2-b1*a2;
	 ll delx=c1*b2-c2*b1;
	 ll dely=a1*c2-a2*c1;
     
	 long double x,y;
	 if(delx==0) x=0.0;
	 else 
	  x=(1.0*delx)/del;

	  if(dely==0)
	  y=0.0;
	  else 
	  y=(1.0*dely)/del;
	//  cout<<fixed<<setprecision(10)<<x<<" "<<y<<endl;
	  
	  
      
//	 return {x,y};

}

double find_dis(double x1,double y1,double x2,double y2)
{
	double ans=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	return ans;
	return sqrt(ans);
}
*/

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

vll used_primes;

void factorization(ll n)
{
	used_primes.clear();
	ll temp_n = n;
	for (int i = 2; i * i <= temp_n; i++)
		if (n % i == 0)
		{
			used_primes.push_back(i);

			n /= i;
		}

	if (n > 1)
		used_primes.push_back(n);
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

int sum_of_digits(int n)
{
	int sum = 0;
	while (n)
	{
		sum += (n % 10);
		n /= 10;
	}

	return sum;
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

vi v1, v2;

bool evaluation(int mid)
{
	for (int i = 0; i < mid; i++)
		v1.push_back(100);

	for (int i = 0; i < mid; i++)
		v2.push_back(0);

	int limit = v1.size() - (v1.size() / 4);

	int sum1 = 0;

	for (int i = v1.size() - 1, cnt = 0; i >= 0, cnt < limit; i--, cnt++)
		sum1 += v1[i];

	int sum2 = 0;
	for (int i = 0; i < limit; i++)
		sum2 += v2[i];

	for (int i = 0; i < mid; i++)
	{
		v1.pop_back();
		v2.pop_back();
	}
	// cout << sum1 << " " << sum2 << endl;

	if (sum1 >= sum2)
		return true;
	return false;
}

bool check(vll v1, vll v2)
{
	for (auto x : v1)
		cout << x << " ";
	cout << endl;
	for (auto x : v2)
		cout << x << " ";
	cout << endl;
	cout << endl;
	for (int i = 0; i < v1.size(); i++)
		if (v1[i] != v2[i])
			return false;
	return true;
}

bool comp(vi v1, vi v2)
{
	int cnt = 0;
	for (int i = 0; i < v1.size(); i++)
		if (v1[i] < v2[i])
			cnt++;

	if (cnt >= 3)
		return true;
	return false;
}

vector<vi> v;

void merge(int lo, int hi)
{
	int mid = (lo + hi) / 2;
	vector<vi> v1, v2;
	for (int i = lo; i <= mid; i++)
		v1.push_back(v[i]);
	for (int i = mid + 1; i <= hi; i++)
		v2.push_back(v[i]);

	vector<vi> vv;
	int i = 0;
	int j = 0;
	while (i < v1.size() && j < v2.size())
	{
		if (comp(v1[i], v2[j]))
			vv.push_back(v1[i++]);
		else
			vv.push_back(v2[j++]);
	}

	while (i < v1.size())
		vv.push_back(v1[i++]);

	while (j < v2.size())
		vv.push_back(v2[j++]);

	int idx = 0;
	for (int x = lo; x <= hi; x++)
		v[x] = vv[idx++];
}

void mergesort(int l, int r)
{
	if (l >= r)
		return;
	int mid = (l + r) / 2;
	mergesort(l, mid);
	mergesort(mid + 1, r);
	merge(l, r);
}

void solve()
{

	v.clear();
	int n;
	cin >> n;
	vector<vi> vv;
	for (int i = 0; i < n; i++)
	{
		vi temp;
		for (int j = 0; j < 5; j++)
		{
			int x;
			cin >> x;
			temp.push_back(x);
		}
		vv.push_back(temp);
		v.push_back(temp);
	}

	mergesort(0, n - 1);

		for (int i = 1; i < n; i++)
		if (comp(v[0], v[i]) == false)
		{
			cout << "-1" << endl;
			return;
		}

	for (int i = 0; i < vv.size(); i++)
		if (vv[i] == v[0])
		{
			cout << i + 1 << endl;
			return;
		}
}

int main()
{

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;

	// precalculation();

	cin >> T;
	for (int i = 1; i <= T; i++)
		solve();
}