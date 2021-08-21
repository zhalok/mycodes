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

int find_number_of_digits(int num)
{
    int cnt = 0;
    while (num)
    {
        num /= 10;
        cnt++;
    }

    return cnt;
}

int find_maximum_digit(vector<int> v)
{
    int mx = 0;
    for (int i = 0; i < v.size(); i++)
        mx = max(mx, find_number_of_digits(v[i]));

    return mx;
}

int find_nth_digit(int num, int n)
{
    for (int i = 0; i < n - 1; i++)
        num /= 10;
    return num % 10;
}

vi v;

void countingSort(int d)
{

    vector<pii> vp;
    for (int i = 0; i < v.size(); i++)
    {
        int nthDigit = find_nth_digit(v[i], d);
        vp.push_back({nthDigit, v[i]});
    }

    int counter[10];
    memset(counter, 0, sizeof counter);

    for (int i = 0; i < vp.size(); i++)
        counter[vp[i].first]++;

    for (int i = 1; i < 10; i++)
        counter[i] += counter[i - 1];

    int temp[v.size()];

    negloop(i, vp.size() - 1, 0)
    {
        temp[counter[vp[i].first] - 1] = vp[i].second;
        counter[vp[i].first]--;
    }

    for (int i = 0; i < v.size(); i++)
        v[i] = temp[i];
}

void radixSort()
{

    int max_digit = find_maximum_digit(v);

    for (int i = 1; i <= max_digit; i++)
        countingSort(i);
}

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    v.clear();
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    radixSort();

    for (auto x : v)
        cout << x << " ";
    cout << endl;
}