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

ll cill(ll a,ll b)
{
	if(a%b==0)
	return a/b;
	return a/b+1;
}


double eval(double x)
{
     double ans= 2*x*x-12*x+7;
     return ans;
}

double ternarysearch(double lo,double hi)
{
  
  while((hi-lo)>eps)
  {
      double p1=(2*lo+hi)/3;
      double p2=(2*hi+lo)/3;
      double evalp1=eval(p1);
      double evalp2=eval(p2);
      if(evalp1<evalp2) hi=p2;
      else lo=p1;

  }
  return lo;

    

}

void solve(){

double l,r;
cin>>l>>r;
double ans=ternarysearch(l,r);
cout<<ans<<endl;



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
 //   freopen("input.txt","r",stdin);
 //   freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
     solve();
}