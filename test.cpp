#include<bits/stdc++.h>
#include<map>
#include<iostream>
#include<math.h>
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
#define sz 10000
#define ub upper_bound
#define lb lower_bound
#define all(v) v.begin(),v.end()
#define eps 1e-8
#define pi acos(-1.0)
 
ll maxx(ll a,ll b)
{
	return a>b?a:b;
}

ll minn(ll a,ll b)
{
	return a<b?a:b;
}

struct node
{
	
	node* next[2];
	node()
	{
	
		next[0]=next[1]=NULL;
	}
};

vector<int>bits; 


void insert(node* cur_node,int n)
{
 
bits.clear();
for(int i=0;i<31;i++)
{
	bits.push_back(n%2);
	n/=2;
}
 
reverse(all(bits));
 
for(int i=0;i<bits.size();i++){
if(cur_node->next[bits[i]]==NULL)
cur_node->next[bits[i]]= new node();
cur_node=cur_node->next[bits[i]];

 
}
 
 
}
 
int search_max(node* cur_node,int n)
{

int m=n; 
bits.clear();
for(int i=0;i<31;i++)
{
    bits.push_back(n%2);
	n/=2;
}

reverse(all(bits));
int res=0;
for(int i=0;i<bits.size();i++)
{
	if(bits[i]==0)
	{
		if(cur_node->next[1]!=NULL){
			res*=2;
			res++;
			cur_node=cur_node->next[1];
		}
		else if(cur_node->next[0]!=NULL)
		{
			res*=2;
			cur_node=cur_node->next[0];
		}
	}
	else {
		if(cur_node->next[0]!=NULL)
		{
			res*=2;
			res++;
			cur_node=cur_node->next[0];
		}
		else if(cur_node->next[1]!=NULL)
		{
			res*=2;
			cur_node=cur_node->next[1];
		}
	}

}

return (res);
 
}

int search_min(node* cur_node,int n)
{

int m=n; 
bits.clear();
for(int i=0;i<31;i++)
{
    bits.push_back(n%2);
	n/=2;
}

reverse(all(bits));
int res=0;
for(int i=0;i<bits.size();i++)
{
	if(bits[i]==0)
	{
		if(cur_node->next[0]!=NULL){
			res*=2;
			
			cur_node=cur_node->next[0];
		}
		else if(cur_node->next[1]!=NULL)
		{
			res*=2;
			res++;
			cur_node=cur_node->next[1];
		}
	}
	else {
		if(cur_node->next[1]!=NULL)
		{
			res*=2;
			
			cur_node=cur_node->next[1];
		}
		else if(cur_node->next[0]!=NULL)
		{
			res*=2;
			res++;
			cur_node=cur_node->next[0];
		}
	}

}

return (res);
 
}

 
 vector<ll>v;
 
 
void solve(int t)
{
	node* root= new node();
	insert(root,0);
	int n;
	cin>>n;
	v.clear();
	
	ll exor=0;
	for(int i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		exor^=x;
		
		v.push_back(exor);
 
	}
   int ans1=0;
   int ans2=inf;
   for(int i=0;i<v.size();i++)
   {
	   
	   ans1=maxx(ans1,search_max(root,v[i]));
	   ans2=minn(ans2,search_min(root,v[i]));
	   insert(root,v[i]);
 
   }



 
   
 
  
   cout<<"Case "<<t<<": ";
   cout<<ans1<<" "<<ans2<<endl;
 
 
 
}
 
int main()
{
 
 
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
int t;
scanf("%d",&t);
//int t;
//cin>>t;
for(int i=1;i<=t;i++)
solve(i);
 
 
 
}