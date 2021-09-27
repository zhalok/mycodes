#include <bits/stdc++.h>
using namespace std;
using namespace std;
#define zhalok Zhalok
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
#define sz 10001
#define ub upper_bound
#define lb lower_bound
#define all(v) v.begin(), v.end()
#define eps 1e-8
#define pi acos(-1.0)

vi v;
set<vi> ans;

void findAllPermutation(int start, int end)
{

    if (start == end)
    {
        ans.insert(v);
        return;
    }

    for (int i = start; i <= end; i++)
    {
        swap(v[start], v[i]);
        findAllPermutation(start + 1, end);
        swap(v[start], v[i]);
    }
}

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        v = nums;
        ans.clear();
        findAllPermutation(0, nums.size() - 1);
        vector<vi> anss;
        for (auto x : ans)
            anss.push_back(x);

        return anss;
    }
};

// int main()
// {

//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);

//     int n;
//     cin >> n;
//     vi v;
//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         cin >> x;
//         v.push_back(x);
//     }
//     Solution sol;
//     vector<vi> ans = sol.permute(v);
//     for (auto x : ans)
//     {
//         for (auto y : x)
//             cout << y << " ";
//         cout << endl;
//     }
// }
