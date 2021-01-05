#include<bits/stdc++.h>
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





void solve()
{
	int n,m;
	cin>>n>>m;
    bool grid[n][m];
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	cin>>grid[i][j];

	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
		if(grid[i][j]==1)
		{
			bool flag1=true;
			bool flag2=true;
			for(int k=0;k<n;k++)
			if(grid[k][j]==0)
			{
				flag1=false;
			    break;
			}

			for(int k=0;k<m;k++)
			if(grid[i][k]==0)
			{
				flag2=false;
				break;
			}
              
			  if(flag1==false&&flag2==false)
			  {
				  cout<<"NO"<<endl;
				  return ;
			  }

		}
	}
    
//	cout<<"HI there"<<endl;
	bool ans[n][m];
	memset(ans,1,sizeof ans);

/*	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++) cout<<ans[i][j]<<" ";
		cout<<endl;
	}
*/
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	if(grid[i][j]==0)
	{
		for(int k=0;k<n;k++) ans[k][j]=0;
		for(int k=0;k<m;k++) ans[i][k]=0;

	}
    
	cout<<"YES"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++) cout<<ans[i][j]<<" ";
		cout<<endl;
	}


}





int main(int args,char * _argc[])
{


    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    ios::sync_with_stdio(false);
//	int n;
//	cin>>n;
//	cout<<n<<endl;
//	printf("%.419lf\n",sqrt(n));
//	int t;
//	cin>>t;
//	while(t--)
	 solve();
    return 0;
}