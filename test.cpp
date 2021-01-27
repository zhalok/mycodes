#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<vector>
#include <utility>
using namespace std;
#define zhalok Zhalok
#define inf 1e9+10
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
#define eps 1e-2
#define pi acos(-1.0)




double dp[sz];
vector<int>cost;
vector<double>prob;

void solve(int t)
{

cost.clear();
prob.clear();
double p;
int n;
cin>>p>>n;
int sum=0;
for(int i=0;i<n;i++)
{
   
    int c;
    double p;
    cin>>c>>p;
    sum+=c;
    cost.push_back(c);
    prob.push_back(p);

}





for(int i=0;i<=sum;i++)
dp[i]=1.0;
dp[0]=0.0;


for(int i=0;i<n;i++)
{
    for(int j=0;j<=sum;j++)
    {
        int next=j+cost[i];
        if(next<=sum)
        dp[next]=min(dp[next],dp[j]+(1-dp[j])*prob[i]);
    }
}





int ans=0;
for(int i=0;i<=sum;i++)
if(dp[i]<p)
ans=i;
cout<<"Case "<<t<<": ";
cout<<ans<<endl;
 
    

}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
      solve(i);
}



