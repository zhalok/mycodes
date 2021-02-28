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

 
ll minn(ll a,ll b)
{
	return a<b?a:b;
}
 
ll maxx(ll a,ll b)
{
	return a>b?a:b;
}



ll cill(ll a,ll b)
{
	if(a%b==0)
	return a/b;
	return a/b+1;
}


/*

void solve_eqn(ll a1,ll b1,ll a2,ll b2,ll c1,ll c2)
{
	 
     ll del=a1*b2-b1*a2;
	 ll delx=c1*b2-c2*b1;
	 ll dely=a1*c2-a2*c1;
     
	 long double x,y;
	 if(delx==0) x=0.0;
	 else 
	  x=(1.0*delx)/del;

	  if(dely==0)
	  y=0.0;
	  else 
	  y=(1.0*dely)/del;
	//  cout<<fixed<<setprecision(10)<<x<<" "<<y<<endl;
	  
	  
      
//	 return {x,y};

}

double find_dis(double x1,double y1,double x2,double y2)
{
	double ans=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	return ans;
	return sqrt(ans);
}


 
ll mod_exp(ll a,ll n,ll mod)
{
	if(n==0) return 1;
	if(n%2==0){
		ll temp=mod_exp(a,n/2,mod);
		return (temp%mod*temp%mod)%mod;
	}
	else {
		ll temp1=a;
		ll temp2=mod_exp(a,n-1,mod);
		return (temp1%mod*temp2%mod)%mod;
	}
	
}
*/

ll abss(ll a)
{
	if(a>=0) return a;
	else return -1*(a);
}



long double get_angle(pii a,pii b,pii c)
{
     int x1=a.first;
	 int y1=a.second;
	 int x2=b.first;
	 int y2=b.second;
	 int x3=c.first;
	 int y3=c.second;
     long double len1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	 long double len2=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	 long double val=((x1-x2)*(x3-x2)+(y1-y2)*(y3-y2))/(len1*len2);
	 return acos(val);

}


long double find_point_dis(pii point1,pii point2)
{
	long double temp_ans;
	temp_ans=((point1.first-point2.first)*(point1.first-point2.first));
	temp_ans+=((point1.second-point2.second)*(point1.second-point2.second));
	return sqrt(temp_ans);
}

int check_sidde(pii p1,pii p2,pii p3)
{
	int x1=p1.first;
	int y1=p1.second;
	int x2=p2.first;
	int y2=p2.second;
	int x3=p3.first;
	int y3=p3.second;

    ll ans=(x3-x1)*(y1-y2)-(y3-y1)*(x1-x2);
	if(ans>=0) return 1;
	else return -1;

}

ll cnt_div(ll n,ll k)
{
	ll cnt=0;
	while(n%k==0)
	{
		cnt++;
		n/=k;
	}
	return cnt;
}

ll gcd(ll a,ll b)
{
	if(a%b==0) return b;
	return gcd(b,a%b);
}

ll lcm(ll a,ll b)
{
	ll g=gcd(a,b);
	return (a*b)/g;
}

bool primechk[sz];

vector<int>primes;

void seive()
{

	for(ll i=2;i*i<sz;i++)
	if(primechk[i]==false)
	for(ll j=i*i;j<sz;j+=i)
	primechk[j]=true;

	for(int i=2;i<sz;i++)
	if(primechk[i]==false)
	primes.push_back(i);
        
	

}
/*
vll v;
vpll ans;
map<int,int>counter;

bool check(int x)
{
	counter.clear();
	ans.clear();
	for(int i=0;i<v.size();i++)
	counter[v[i]]++;
    
	for(int i=v.size();i>=0;i--)
	if(counter[v[i]]>0)
	{
		counter[v[i]]--;
		if(counter[x-v[i]]>0){
		ans.push_back({v[i],x-v[i]});
		counter[x-v[i]]--;
		counter[v[i]]--;
		x=v[i];
		}
		
	}
	

	if(ans.size()*2==v.size()) return true;
	else return false;

	

}
*/
/*
vi v;
map<int,bool>visited;

int check()
{
	visited.clear();
	
	int ans=0;
	for(int i=0;i<v.size();i++){
		int lasten=0;
		bool flag=false;
		for(int j=0;j<v.size();j++)
		{
             if((visited[j]==false)&&v[j]>lasten)
			{
				flag=true;
				lasten=v[j];
				visited[j]=true;

			}
		}
		if(flag) ans++;
	}
	//for(int i=0;i<v.size();i++) cout<<visited[i]<<" ";
	//cout<<endl;

	return ans;
}

*/



struct node{

bool flag;
int counter;
node *cur[26];
node()
{
	counter=0;
	flag=false;
	for(int i=0;i<26;i++)
	cur[i]=NULL;

}

};

class TRIE{

void insert(node* cur_node,string name)
{
	for(int i=0;i<name.size();i++){
    if(cur_node->cur[name[i]-'a']==NULL)
	cur_node->cur[name[i]-'a']=new node();
	cur_node=cur_node->cur[name[i]-'a'];
	
	}
	cur_node->flag=1;
	
}

bool search(node* cur_node,string s)
{
	
	for(int i=0;i<s.size();i++)
	if(cur_node->cur[s[i]-'a']==NULL) return false;
	else cur_node=cur_node->cur[s[i]-'a'];
	return cur_node->flag;
}


};


vi adj[sz+1];
vi cost[sz+1];
ll level[sz+1];
int sparse_table[sz+1][20];
int parent[sz+1];
int n,m;

void dfs(int node,int par)
{
	
	parent[node]=par;
	for(int i=0;i<adj[node].size();i++)
	if(adj[node][i]!=parent[node])
	{
		level[adj[node][i]]=level[node]+cost[node][i];
		dfs(adj[node][i],node);
	}

}

void create_sparse_table()
{
   for(int j=1;j<=log2(n);j++)
   {
	   for(int i=1;i<=n;i++)
	   {
		   int par=sparse_table[i][j-1];
		   if(par!=-1)
		   sparse_table[i][j]=sparse_table[par][j-1];
	   }
   }
}

int lca(int a,int b)
{
	if(level[b]<level[a]) swap(a,b);
	int d=level[b]-level[a];
	while(d>0)
	{
		int jump=log2(d);
		b=sparse_table[b][jump];
		d-=(1<<jump);
	}

	if(a==b) return a;

    for(int i=log2(n);i>=0;i--)
	if(sparse_table[a][i]!=-1&&sparse_table[a][i]!=sparse_table[b][i])
	{
		a=sparse_table[a][i];
		b=sparse_table[b][i];
	}
	return parent[a];



}
void preprocess()
{
	for(int i=0;i<=n;i++)
	{
		parent[i]=-1;
		adj[i].clear();
		cost[i].clear();
	    level[i]=0;
		for(int j=0;j<=log2(n);j++)
		sparse_table[i][j]=-1;
	}
}

void solve(int t)
{

scanf("%d%d",&n,&m);
preprocess();
for(int i=0;i<n-1;i++)
{
	int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
	adj[a].push_back(b);
	adj[b].push_back(a);
	cost[a].push_back(c);
	cost[b].push_back(c);
}
dfs(1,-1);
create_sparse_table();
while(m--)
{
int a,b;
scanf("%d%d",&a,&b);
int x=lca(a,b);
cout<<(level[a]-level[x]) + (level[b]-level[x])<<endl;
}




}




int main()
{


//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
int t;
scanf("%d",&t);
//int t;
//cin>>t;
for(int i=1;i<=t;i++)
solve(i);


 
}






/*

ll counter[sz];
 
bool primechk[sz];

ll prime_counter[sz];



void sieve()
{
	for(ll i=2;i<sz;i++)
	if(primechk[i]==false)
	{
		;
		for(ll j=i;j<sz;j+=i)
		{
		primechk[j]=true;
		prime_counter[i]+=counter[j];
		}
	}

}

*/

/*
map<int,int>counter;
ll ans1=0;
ll ans2=1;
ll mn=inf;
ll cost[100000];
vi adj1[100000];
vi adj2[100000];
bool visited[100000];
stack<int>st;

void dfs1(int n)
{
	visited[n]=true;
	for(int i=0;i<adj1[n].size();i++)
	if(visited[adj1[n][i]]==false)
	dfs1(adj1[n][i]);
	st.push(n);
}
 
int dfs2(int n)
{
	counter[cost[n]]++;
	mn=minn(mn,cost[n]);
	visited[n]=true;
	int cnt=0;
	for(int i=0;i<adj2[n].size();i++)
	if(!visited[adj2[n][i]])
	cnt+=dfs2(adj2[n][i]);

	
	return cnt+1;
}
 
 
int kossoraju(int n)
{
	int ans=1001;
	memset(visited,false,sizeof visited);
 
	for(int i=0;i<n;i++)
	if(!visited[i]) dfs1(i);
 
	memset(visited,false,sizeof visited);
 
	while(st.size())
	{
		if(visited[st.top()]==false)
		{   counter.clear();
		    mn=inf;
			int temp_ans=dfs2(st.top());
			ans1+=mn;
			
			ans2*=counter[mn];
			ans2%=MOD;
			if(temp_ans>1) ans=min(ans,temp_ans);
		}
		st.pop();
	}
	return ans;
}

*/
