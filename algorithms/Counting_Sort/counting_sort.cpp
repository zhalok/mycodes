#include <bits/stdc++.h>
using namespace std;
using namespace std;
#define zhalok Zhalok
#define inf 1000000
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

void countSort(vi &v)
{

	vi ans;
	ans.resize(v.size());

	int mx = *max_element(all(v));
	int counter[mx + 1];
	memset(counter, 0, sizeof counter);

	for (auto x : v)
		counter[x]++;

	for (int i = 1; i <= mx; i++)
		counter[i] += counter[i - 1];

		for (int i = 0; i < v.size(); i++)
	{
		ans[counter[v[i]] - 1] = v[i];
		counter[v[i]]--;
	}

	for (int i = 0; i < ans.size(); i++)
		v[i] = ans[i];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	vi v;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	countSort(v);

	for (auto x : v)
		cout << x << " ";
	cout << endl;

	return 0;
}
