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
 
struct node
{
	ll counter;
	bool flag;
	node* next[2];
	node()
	{
		counter=0;
		flag=false;
		next[0]=next[1]=NULL;
	}
};
 
void insert(node* cur_node,int n)
{
 
vector<int>v;
for(int i=0;i<32;i++)
{
	v.push_back(n%2);
	n/=2;
}
 
reverse(all(v));
 
for(int i=0;i<v.size();i++){
if(cur_node->next[v[i]]==NULL)
cur_node->next[v[i]]= new node();
cur_node=cur_node->next[v[i]];
cur_node->counter++;
 
}
cur_node->flag=true;
 
 
}
 
ll search(node* cur_node,int n,int k)
{
 
vector<int>vn,vk;
 
 
for(int i=0;i<32;i++)
{
	vn.push_back(n%2);
	vk.push_back(k%2);
	n/=2;
	k/=2;
}
 
reverse(all(vn));
reverse(all(vk));
 
ll res=0;
 
for(int i=0;i<32;i++)
{
 
 if(vn[i]==0)
 {
	 if(vk[i]==0)
	 {
		 if(cur_node->next[1]!=NULL)
		 res+=cur_node->next[1]->counter;
		 if(cur_node->next[0]!=NULL)
		 cur_node=cur_node->next[0];
         else break;
	 }
	 else 
	 {
		 if(cur_node->next[1]!=NULL)
		 cur_node=cur_node->next[1];
		 else break;
	 }
 }
 else{
 
     if(vk[i]==0)
	 {
		 if(cur_node->next[0]!=NULL)
		 res+=cur_node->next[0]->counter;
		 if(cur_node->next[1]!=NULL)
		 cur_node=cur_node->next[1];
         else break;
	 }
	 else 
	 {
		 if(cur_node->next[0]!=NULL)
		 cur_node=cur_node->next[0];
		 else break;
	 }
 
 
 }
 
}
 
if(cur_node->flag)
res+=cur_node->counter;
return res;
 
}
 
 
 
 
void solve(int t)
{
	node* root= new node();
	insert(root,0);
	int n,k;
	scanf("%d%d",&n,&k);
	vector<ll>v;
	vector<ll>v1;
	ll exor=0;
	for(int i=0;i<n;i++)
	{
		ll x;
		scanf("%lld",&x);
		exor^=x;
		v1.push_back(x);
		v.push_back(exor);
 
	}
   ll ans=0;
   for(int i=0;i<v.size();i++)
   {
	   
	   ans+=search(root,v[i],k);
	   insert(root,v[i]);
 
   }
 
 
 
 
   
 
  
  printf("%lld\n",ans);
   
 
 
 
}
 
int main()
{
 
 
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
//int t;
//scanf("%d",&t);
//int t;
//cin>>t;
//for(int i=1;i<=t;i++)
solve(1);
 
 
 
}