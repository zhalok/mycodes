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

void solve(){

int s,n;
cin>>s>>n;


vpll p;
for(int i=0;i<n;i++)
{
    ll x,y;
    cin>>x>>y;
    p.push_back({x,-y});
}
sort(all(p));


//for(auto x:p) cout<<x.first<<" "<<x.second<<endl;

//cout<<endl;

for(int i=0;i<p.size();i++)
{
    ll loose=p[i].first;
    ll gain=-p[i].second;
    if(s>loose){
        
        s+=gain;
      //  cout<<loose<<" "<<gain<<endl;
    }
    else {
        cout<<"NO"<<endl;
        return;
    }
}


cout<<"YES"<<endl;



}


int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false);
     solve();
}