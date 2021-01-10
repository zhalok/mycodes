#include<bits/stdc++.h>
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
#define sz 10000001
#define ub upper_bound
#define lb lower_bound
#define all(v) v.begin(),v.end()
#define eps 1e-6


 
ll minn(ll a,ll b)
{
	return a<b?a:b;
}
 
 
 
ll maxx(ll a,ll b)
{
	return a>b?a:b;
}

/*

ll cill(ll a,ll b)
{
	if(a%b==0)
	return a/b;
	return a/b+1;
}

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





void solve()
{ 

ll x0,y0,x1,y1;
cin>>x0>>y0>>x1>>y1;


map<ll,ll>mn;
map<ll,ll>mx;
vector< pair< ll , pll > > v;
int n;
cin>>n;
for(int i=0;i<n;i++)
{
	ll r,x,y;
	cin>>r>>x>>y;
	v.push_back({r,{x,y}});
}

for(int i=0;i<n;i++)
{
	int val=v[i].ff;
	int mxval=v[i].ss.ss;
	int mnval=v[i].ss.ff;
	mx[val]=maxx(mx[val],mxval);
	mn[val]=maxx(mn[val],mxval);

}

for(int i=0;i<n;i++)
{
	ll val=v[i].ff;
	ll mnval=v[i].ss.ff;
	mn[val]=minn(mn[val],mnval);
}

set<ll>s;
for(int i=0;i<n;i++)
s.insert(v[i].first);

vector<ll>unv;
for(auto x:s) unv.push_back(x);

bool flag1=false;
bool flag2=false;
for(auto x:unv)
{   // cout<<x<<" "<<mn[x]<<" "<<mx[x]<<endl;

	if(x==x0&&(mn[x]<=y0&&mx[x]>=y0)) flag1=true;
	if(x==x1&&(mn[x]<=y1&&mx[x]>=y1)) flag2=true;
}




if(flag1&&flag2)
{
	int idx1=-1;
	int idx2=-1;
	for(int i=0;i<unv.size();i++)
	if(unv[i]==x0||unv[i]==x1) {
		idx1=i;
		break;
	}
	for(int i=unv.size()-1;i>=0;i--)
	if(unv[i]==x0||unv[i]==x1)
	{
		idx2=i;
		break;
	}

for(int i=idx1+1;i<=idx2;i++)
if(unv[i]-unv[i-1]!=1) {
	cout<<"hi"<<endl;
	cout<<"-1"<<endl;
	return ;
}
else {
	if(mx[unv[i]]<mn[unv[i-1]]||mn[unv[i]]>mx[unv[i-1]]) {
		cout<<"hello"<<endl;
		cout<<"-1"<<endl;
		return ;
	}
}

cout<<(abss(x0-x1)+abss(y0-y1))-1<<endl;


}else cout<<"-1"<<endl;






}





int main()
{

freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
//int t;
//cin>>t;
//while(t--)
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

