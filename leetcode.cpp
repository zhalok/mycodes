#include<bits/stdc++.h>
using namespace std;
using namespace std;
#define zhalok Zhalok
#define inf 1000000
#define ll long long int  
#define ull unsigned long long 
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define negloop(i,a,b) for(ll i=a;i>=b;i--)
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define pb push_back
#define be begin()
#define en end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define ff first
#define ss second
#define MOD 1000000007
#define sz 10001
#define ub upper_bound
#define lb lower_bound
#define all(v) v.begin(),v.end()
#define eps 1e-8
#define pi acos(-1.0)

class Solution {
    
public:

bool isPalindrome(string s)
{
  int i=0;
  int j=s.size()-1;
  while(i<=j)
  {
    if(s[i]!=s[j]) return false;
    i++;
    j--;
  }

  return true;
}

bool check(string s,int len)
{
    int i=0;
    int j=len-1;
    while(j<s.size())
    {
      string temp;
      for(int k=i;k<=j;k++)
      temp.push_back(s[k]);
      if(isPalindrome(temp)) return true;
      i++;
      j++;
    }

    return false;
}

string find_palindrome_substring(string s,int len)
{
   int i=0;
   int j=len-1;
   string ans;
   while(j<s.size())
   {
     string temp;
     for(int k=i;k<=j;k++)
     temp.push_back(s[k]);
     if(isPalindrome(temp))
     ans = temp;
     i++;
     j++;
   }

   return ans;
}

int process(string s,int parity)
{
  int mx=0;
  int lo=1;
  int hi=s.size();
  if(lo%2!=parity) lo++;
  if(hi%2!=parity) hi--;
  while(lo<=hi)
  {
    int mid = (lo+hi)/2;
    if(mid%2!=parity) mid--;
    if(mid<lo) break;
    if(check(s,mid)){
      mx=max(mx,mid);
      lo=mid+2;
    }
    else hi=mid-2;
  }

  return mx;
}


string longestPalindrome(string s) {
      
    int mx=max(process(s,0),process(s,1));

    return find_palindrome_substring(s,mx);


    
        
    }

    
     
     
     
    

};

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Solution solution;
    string s;
    cin>>s;
    // cout<<solution.check(s,3)<<endl;
    cout<<solution.longestPalindrome(s)<<endl;
    

}