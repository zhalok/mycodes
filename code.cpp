#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include <utility>
using namespace std;
#define zhalok Zhalok
#define inf 1e9
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
#define sz 100001
#define ub upper_bound
#define lb lower_bound
#define all(v) v.begin(),v.end()
#define eps 1e-6

pair<long double,long double> quadratic_eqn_solve(ll a,ll b,ll c)
{
    long double del=sqrt(b*b-4*a*c);
    long double ans1=(1.0)*(del-b)/(2*a);
    long double ans2=(1.0)*(-del-b)/(2*a);
    return {ans1,ans2};

    
}


ll minn(ll a,ll b)

{
    return a<b?a:b;
}

ll cill(ll a,ll b)
{
	if(a%b==0)
	return a/b;
	return a/b+1;
}

ll eval(ll x)
{
    ll ans= 2*x*x-12*x+7;
     return ans;
}

ll ternarysearch(ll lo,ll hi)
{
  
  while((hi-lo)>1)
  {
      ll mid=((lo+hi)/2);
      ll left_val=eval(mid);
      ll right_val=eval(mid+1);
      if(left_val<=right_val)
      hi=mid;
      else lo=mid;

  }
  
  return minn(eval(lo),eval(lo+1));

    

}

 


void solve(){

int n ,k;
cin>>n>>k;
vi v;
map<ll,int>pref;
map<ll,int>suf;
ull ans=0;
for(int i=0;i<n;i++)
{
    int x;
    cin>>x;
    suf[x]++;
    v.push_back(x);


}




for(int i=0;i<v.size();i++)
{
    suf[v[i]]--;
    if(v[i]%k==0)
    {ll temp_ans=(pref[v[i]/k]*suf[v[i]*k]);
     ans+=temp_ans;
    }  
    pref[v[i]]++;
    
}


cout<<ans<<endl;




}


int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false);
   // int t;
   // cin>>t;
   // while(t--)
     solve();
}