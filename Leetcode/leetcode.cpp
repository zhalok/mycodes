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

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        reverse(all(num1));
        reverse(all(num2));
        int mx = max(num1.size(), num2.size());
        int arr1[mx + 1];
        int arr2[mx + 1];
        int arr[mx + 1];
        memset(arr1, 0, sizeof arr1);
        memset(arr2, 0, sizeof arr2);
        for (int i = 0; i < num1.size(); i++)
            arr1[i] = num1[i] - '0';
        for (int i = 0; i < num2.size(); i++)
            arr2[i] = num2[i] - '0';
        int carry = 0;
        for (int i = 0; i <= mx; i++)
        {
            int sum = (arr1[i] + arr2[i] + carry) % 10;
            carry = (arr1[i] + arr2[i] + carry) / 10;
            arr[i] = sum;
        }

        string ans;
        for (int i = 0; i < mx; i++)
            ans += (arr[i] + '0');
        if (arr[mx] != 0)
            ans += (arr[mx] + '0');
        reverse(all(ans));
        return ans;
    }

    string numToString(int n)
    {
        string ans;
        while (n)
        {
            int temp = n % 10;
            n /= 10;
            ans += (temp + '0');
        }
        reverse(all(ans));
        return ans;
    }

    string addAllStrings(vector<string> vs)
    {
        string init = "";
        for (int i = 0; i < vs.size(); i++)
            init = addStrings(init, vs[i]);
        return init;
    }

    string multiply(string num1, string num2)
    {
        vector<string> vv;

        if (num1 == "0" || num2 == "0")
            return "0";

        if (num1.size() > num2.size())
        {
            // cout << "HELLO" << endl;
            return multiply(num2, num1);
        }

        reverse(all(num1));
        reverse(all(num2));

        for (int i = 0; i < num1.size(); i++)
        {
            string ans;

            int carry = 0;

            for (int j = 0; j < num2.size(); j++)
            {
                int digit1 = num1[i] - '0';
                int digit2 = num2[j] - '0';
                int sum = (digit1 * digit2 + carry) % 10;
                carry = (digit1 * digit2 + carry) / 10;
                ans += (sum + '0');
                // cout << sum << " " << carry << endl;
            }

            if (carry)
                ans += (carry + '0');

            reverse(all(ans));

            for (int k = 0; k < i; k++)
                ans += '0';
            vv.push_back(ans);
        }

        // for (auto x : vv)
        //     cout << x << endl;

        string ans = addAllStrings(vv);

        return ans;
    }
};

// int main()
// {

//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     string s1, s2;
//     cin >> s1 >> s2;
//     Solution Solution;
//     cout << Solution.multiply(s1, s2) << endl;
// }
