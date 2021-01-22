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
#define sz 5001
#define ub upper_bound
#define lb lower_bound
#define all(v) v.begin(),v.end()
#define eps 1e-2
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

bool check(string s,string t)
{
	if(t.size()>s.size()) return false;
	if(s.size()%t.size()) return false;
	int i=0;
	int j=t.size()-1;
	string temp;
	while(j<s.size())
	{
		temp.clear();
		for(int k=i;k<=j;k++)
		temp.push_back(s[k]);
		if(temp==t){
			i=j+1;
			j=i+t.size()-1;
		}else return false;
	}
	return true;
}

int dp[sz][sz];
int par[sz][sz];
vi adj[sz],cost[sz];

ll dfs(int node,int counter)
{
    if(node==1) {
		if(counter==1) return 0;
		else return inf+10;
	}

	if(counter<1) return inf+10;
	if(dp[node][counter]!=-1)return dp[node][counter];
	ll ans=inf;
    
	for(int i=0;i<adj[node].size();i++)
	{
		int new_node=adj[node][i];
		ll temp_ans=dfs(new_node,counter-1)+cost[node][i];
		if(temp_ans<ans)
		{
			ans=temp_ans;
			par[node][counter]=new_node;
		}
	}

	return dp[node][counter]=ans;

   

}


void print_path(int n,int t)
{
	memset(dp,-1,sizeof dp);
	memset(par,-1,sizeof par);
	int idx=-1;
	for(int i=n;i>=1;i--)
	{
		ll time=dfs(n,i);
		if(time<=t)
		{
			idx=i;
			break;
		}
		
	}

    vector<int>path;
	int x=n;
	while(x!=-1)
	{
		path.push_back(x);
		x=par[x][idx--];
	}

	cout<<path.size()<<endl;
	reverse(all(path));
	for(auto x:path) cout<<x<<" ";
	cout<<endl;

}

vector<int> s;
void pre_order_traversal(ll n)
{
	if(n<2){ s.push_back(n); return ; }
	pre_order_traversal((n/2));
	pre_order_traversal(n%2);
	pre_order_traversal((n/2));
}


void solve()
{ 

ll n,l,r;
cin>>n>>l>>r;

ll ans=0;
pre_order_traversal(n);
for(int i=l-1;i<r;i++)
if(s[i]==1) ans++;
cout<<ans<<endl; 



}



int main()
{

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//int t;
//cin>>t;
//for(int i=1;i<=t;i++)
solve();

 
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
