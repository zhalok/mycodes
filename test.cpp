#include<bits/stdc++.h>
#include<map>
#include<iostream>
#include<math.h>
#include<vector>
#include <utility>
using namespace std;
#define zhalok Zhalok
#define inf 1000000001
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
int main()
{
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	vi v1,v2;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		v1.push_back(x);
	}

	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v2.push_back(x);
	}

	


	  
		 if(v1.size()<v2.size()){
        int gap=v2.size()-v1.size();    
        for(int i=0;i<gap;i++)
        v1.push_back(0);
        }
        else{
           int gap=v1.size()-v2.size();
            for(int i=0;i<gap;i++)
        v2.push_back(0);
             
            }

        v1.push_back(0);
        v2.push_back(0);

        for(auto x:v1) cout<<x<<" ";
		cout<<endl;
		for(auto x:v2) cout<<x<<" ";
		cout<<endl;
	

        vi v(v1.size(),0);
        // for(int i=0;i<v.size()-1;i++) cout<<v[i]<<" ";
        for(int i=0;i<v.size()-1;i++){
        v[i]=(v1[i]+v2[i]+v[i])%10;
        v[i+1]=(v1[i]+v2[i]+v[i])/10;
        }

        if(v[v.size()-1]==0)
        v.pop_back();

        // reverse(all(v));

        for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
        cout<<endl;
}