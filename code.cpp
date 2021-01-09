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
#define sz 10000001
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

int n;
cin>>n;
vi v;
for(int i=0;i<n;i++)
{
    int x;
    cin>>x;
    v.push_back(x);
}

vi ans(v.size(),0);
int cnt=0;
int mx=0;
int total=0;
for(int i=1;i<v.size()-1;i++)
if((v[i]>v[i-1]&&v[i]>v[i+1])||(v[i]<v[i-1]&&v[i]<v[i+1]))
ans[i]=1;

for(auto x:ans) cout<<x<<" ";
cout<<endl;


//cout<<total<<" "<<mx<<" "<<endl;





/*
int h,l,r,k;
while(1)
{
    cin>>h>>l>>r>>k;
    if(h==0&&l==0&&r==0&&k==0) break;
    ll a=(k*k-1);
    ll b=2*r;
    ll c=(k*k*l*l)-(h*h+r*r);
    ll del=b*b-4*a*c;
    cout<<del<<endl;
    cout<<a<<" "<<b<<" "<<c<<endl;
}
*/

}


int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
     solve();
}