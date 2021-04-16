#include<bits/stdc++.h>
#include<map>
#include<iostream>
#include<math.h>
#include<vector>
#include <utility>
using namespace std;
#define zhalok Zhalok
#define inf 1e9+1
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
#define sz 300001
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
*/

 
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

// bool primechk[sz];

// vector<int>primes;

// void seive()
// {

// 	for(ll i=2;i*i<sz;i++)
// 	if(primechk[i]==false)
// 	for(ll j=i*i;j<sz;j+=i)
// 	primechk[j]=true;

// 	for(int i=2;i<sz;i++)
// 	if(primechk[i]==false)
// 	primes.push_back(i);
        
	

// }
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



// struct node{

// bool flag;
// int counter;
// node *cur[26];
// node()
// {
// 	counter=0;
// 	flag=false;
// 	for(int i=0;i<26;i++)
// 	cur[i]=NULL;

// }

// };

// class TRIE{

// void insert(node* cur_node,string name)
// {
// 	for(int i=0;i<name.size();i++){
//     if(cur_node->cur[name[i]-'a']==NULL)
// 	cur_node->cur[name[i]-'a']=new node();
// 	cur_node=cur_node->cur[name[i]-'a'];
	
// 	}
// 	cur_node->flag=1;
	
// }

// bool search(node* cur_node,string s)
// {
	
// 	for(int i=0;i<s.size();i++)
// 	if(cur_node->cur[s[i]-'a']==NULL) return false;
// 	else cur_node=cur_node->cur[s[i]-'a'];
// 	return cur_node->flag;
// }


// };


// vi adj[sz+1];
// vi cost[sz+1];
// ll level[sz+1];
// int sparse_table[sz+1][20];
// int parent[sz+1];
// int n,m;

// void dfs(int node,int par)
// {
	
// 	parent[node]=par;
// 	for(int i=0;i<adj[node].size();i++)
// 	if(adj[node][i]!=parent[node])
// 	{
// 		level[adj[node][i]]=level[node]+cost[node][i];
// 		dfs(adj[node][i],node);
// 	}

// }

// void create_sparse_table()
// {
//    for(int j=1;j<=log2(n);j++)
//    {
// 	   for(int i=1;i<=n;i++)
// 	   {
// 		   int par=sparse_table[i][j-1];
// 		   if(par!=-1)
// 		   sparse_table[i][j]=sparse_table[par][j-1];
// 	   }
//    }
// }

// int lca(int a,int b)
// {
// 	if(level[b]<level[a]) swap(a,b);
// 	int d=level[b]-level[a];
// 	while(d>0)
// 	{
// 		int jump=log2(d);
// 		b=sparse_table[b][jump];
// 		d-=(1<<jump);
// 	}

// 	if(a==b) return a;

//     for(int i=log2(n);i>=0;i--)
// 	if(sparse_table[a][i]!=-1&&sparse_table[a][i]!=sparse_table[b][i])
// 	{
// 		a=sparse_table[a][i];
// 		b=sparse_table[b][i];
// 	}
// 	return parent[a];



// }

// int n;
// pair<pll,pll> tree[8*sz];
// vll v;
 
 
// void build(int idx,int lo,int hi)
// {
// 	// max sum total sum prefix suffix
	
//     if(lo==hi) {
    	
//     	tree[idx]={{v[lo],v[lo]},{v[lo],v[lo]}};
//     	return ;
    	
// 	}
	
// 	int mid=(lo+hi)/2;
// 	int left=2*idx+1;
// 	int right=left+1;
// 	build(left,lo,mid);
// 	build(right,mid+1,hi);
	
//     ll left_max=tree[left].ff.ff;
//     ll left_sum=tree[left].ff.ss;
//     ll left_pref=tree[left].ss.ff;
//     ll left_suf=tree[left].ss.ss;
    
//     ll right_max=tree[right].ff.ff;
//     ll right_sum=tree[right].ff.ss;
//     ll right_pref=tree[right].ss.ff;
//     ll right_suf=tree[right].ss.ss;
	
//     ll cross_max=left_suf+right_pref;
	
// 	ll par_max,par_sum,par_pref,par_suf;
   
//      par_max=maxx(left_max,maxx(right_max,cross_max));
//      par_sum=left_sum+right_sum;
//      par_pref=maxx(left_pref,left_sum+right_pref);
//      par_suf=maxx(right_suf,right_sum+left_suf);
    
//     tree[idx]={{par_max,par_sum},{par_pref,par_suf}};
    
		
	
//  } 
 
 
 
// void update(int idx,int lo,int hi,int pos,int val)
// {
// 	// max sum total sum prefix suffix
// 	if(lo>pos or hi<pos) return ;
	
//     if(lo==hi) {
    	
//     	tree[idx]={{val,val},{val,val}};
//     	return ;
    	
// 	}
	
// 	int mid=(lo+hi)/2;
// 	int left=2*idx+1;
// 	int right=left+1;
// 	update(left,lo,mid,pos,val);
// 	update(right,mid+1,hi,pos,val);
	
//     ll left_max=tree[left].ff.ff;
//     ll left_sum=tree[left].ff.ss;
//     ll left_pref=tree[left].ss.ff;
//     ll left_suf=tree[left].ss.ss;
    
//     ll right_max=tree[right].ff.ff;
//     ll right_sum=tree[right].ff.ss;
//     ll right_pref=tree[right].ss.ff;
//     ll right_suf=tree[right].ss.ss;
 
// 	ll cross_max=left_suf+right_pref;
// 	ll par_max,par_sum,par_pref,par_suf;
	
// 	par_max=maxx(left_max,maxx(right_max,cross_max));
//     par_sum=left_sum+right_sum;
//     par_pref=maxx(left_pref,left_sum+right_pref);
//     par_suf=maxx(right_suf,right_sum+left_suf);
//     tree[idx]={{par_max,par_sum},{par_pref,par_suf}};
// } 
 
//  pair<pll,pll> query(int idx,int lo,int hi,int qlo,int qhi)
//  {
    

//     if(qhi<lo or qlo>hi) return {{-inf,-inf},{-inf,-inf}};
    
//     if(qhi>=hi and qlo<=lo) return tree[idx];
 
	
// 	int mid=(lo+hi)/2;
// 	int left=2*idx+1;
// 	int right=left+1;
	
// //	if(mid<=qlo) return query(right,mid+1,hi,qlo,qhi);
// //	if(mid>=qhi) return query(left,lo,mid,qlo,qhi);
	
	
//     pair<pll,pll> left_ans=query(left,lo,mid,qlo,qhi);
// 	pair<pll,pll> right_ans=query(right,mid+1,hi,qlo,qhi);
	
//     ll left_max=left_ans.ff.ff;
//     ll left_sum=left_ans.ff.ss;
//     ll left_pref=left_ans.ss.ff;
//     ll left_suf=left_ans.ss.ss;
    
//     ll right_max=right_ans.ff.ff;
//     ll right_sum=right_ans.ff.ss;
//     ll right_pref=right_ans.ss.ff;
//     ll right_suf=right_ans.ss.ss;
	
//     ll cross_max=left_suf+right_pref;
	
// 	ll par_max,par_sum,par_pref,par_suf;
	
//     par_max=maxx(left_max,maxx(right_max,cross_max));
//     par_sum=left_sum+right_sum;
//     par_pref=maxx(left_pref,left_sum+right_pref);
//     par_suf=maxx(right_suf,right_sum+left_suf);
    
//     return {{par_max,par_sum},{par_pref,par_suf}};
 
	
 	
 	
//  }

int n,q;
vll v;
ll tree[4*sz];

void build_for_sum(int idx,int lo,int hi)
{
	if(lo == hi) {
		tree[idx]=v[lo];
		return ;
	}

	int mid = (lo + hi)/2;
	int left = 2*idx+1;
	int right = 2*idx+2;
	
	build_for_sum(left,lo,mid);
	build_for_sum(right,mid+1,hi);
	tree[idx]=tree[left]+tree[right];
}


void build_for_min(int idx,int lo,int hi)
{
	if(lo==hi)
	{
		tree[idx]=v[lo];
		return ;
	}

	int mid = (lo+hi)/2;
	int left = 2*idx+1;
	int right = 2*idx+2;
	build_for_min(left,lo,mid);
	build_for_min(right,mid+1,hi);
	tree[idx]=minn(tree[left],tree[right]);
}


void update_for_sum(int idx,int lo,int hi,int upidx,int val)
{
	if(lo>upidx||hi<upidx) return ;
	if(lo == hi)
	{
		// cout<<"Updaate is called"<<endl;
		tree[idx]=val;
		return ;
	}

	int mid = (lo+hi)/2;
	int left = 2*idx+1;
	int right = 2*idx+2;
	update_for_sum(left,lo,mid,upidx,val);
	update_for_sum(right,mid+1,hi,upidx,val);

	tree[idx] = tree[left]+tree[right];

}

// void update_for_min(int idx,int lo,int hi,int upidx,int val)
// {

// 	if(lo>upidx||hi<upidx) return ;
// 	if(lo == hi)
// 	{
// 		// cout<<"Updaate is called"<<endl;
// 		tree[idx]=val;
// 		return ;
// 	}

// 	int mid = (lo+hi)/2;
// 	int left = 2*idx+1;
// 	int right = 2*idx+2;
// 	update_for_min(left,lo,mid,upidx,val);
// 	update_for_min(right,mid+1,hi,upidx,val);

// 	tree[idx] = minn(tree[left],tree[right]);
	
// }

ll query_of_sum(int idx,int lo,int hi,int qlo,int qhi)
{
	if(qlo>hi||qhi<lo) return 0;
	if(qlo<=lo&&qhi>=hi) return tree[idx];

	int mid = (lo+hi)/2;
	int left = 2*idx+1;
	int right = 2*idx+2;
	return query_of_sum(left,lo,mid,qlo,qhi) + query_of_sum(right,mid+1,hi,qlo,qhi);


}


// ll query_for_min(int idx,int lo,int hi,int qlo,int qhi)
// {
//     if(qlo>hi||qhi<lo) return 100001;
// 	if(qlo<=lo&&qhi>=hi) return tree[idx];
    
// 	int mid = (lo+hi)/2;
// 	int left = 2*idx+1;
// 	int right = 2*idx+2;

// 	return minn(query_for_min(left,lo,mid,qlo,qhi),query_for_min(right,mid+1,hi,qlo,qhi));
	

// }



ll query_for_kth_one(int idx,int lo,int hi,int k)
{
	if(lo==hi)
	return hi;
	
    int mid = (lo+hi)/2;
	int left = 2*idx+1;
	int right = 2*idx+2;
	
    if(tree[right]>=k) return query_for_kth_one(right,mid+1,hi,k);
	else return query_for_kth_one(left,lo,mid,k-tree[right]);
    
	return 0;

}







ll get_digit_sum(ll n)
{
	ll sum =0 ;
	while(n)
	{
		sum+=(n%10);
		n/=10;
	}
	return sum;
}

ll count_digits(ll n)
{
	ll ans=0;
	while(n)
	{
      ans++;
	  n/=10;
	}
	return ans;
}

ll dp[100001];


ll lis(int idx)
{
   
    if(idx==n) return 1;
	if(dp[idx]!=-1) return dp[idx];
	ll ans = 0;
	for(int i=idx+1;i<v.size();i++)
	if(v[i]>v[idx])
	{
		ll temp_ans= 1+ lis(i);
		ans+=temp_ans;
	}
	return dp[idx]=ans;
	

}

// bool primes[17];
// bool flag=false;
// bool check[17];
// int n;
// vi ans;
// vi anss;

// void get_solution()
// {
// 	if(flag) return ;
// 	bool flag1=true;
// 	for(int i=2;i<=n;i++)
// 	if(check[i]==false)
// 	{
// 		if(primes[ans.back()+i])
// 		{
// 			flag1=false;
// 			check[i]=true;
// 			ans.push_back(i);
// 			get_solution();
// 			check[i]=false;
// 			ans.pop_back();

// 		}


// 	}

// 	if(flag1)
// 	{
// 		if(primes[ans.back()+ans[0]])
// 		{
// 			anss=ans;
// 			flag=true;
// 			return ;
// 		}
// 	}
// }

void solve(int t)
{

map<int,int>mp1,mp2;
cin>>n;
vpii points;
int mn = 100000000;
int mx = 0;
for(int i=0;i<n;i++)
{
	int x,y;
	cin>>x>>y;
	points.push_back({x,y});
	mn=minn(mn,x);
	mx=maxx(mx,y);

}

for(int i=1;i<=mx;i++)
{
	mp1[i]=-1;
	mp2[i]=-1;
}

for(int i=0;i<points.size();i++)
{
	mp1[points[i].second]=points[i].first;
	mp2[points[i].first]=points[i].second;
}

for(int i=1;i<=mx;i++)
{
	
}






}

 
 
int main()
{

// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
	
//int t;
//scanf("%d",&t);
// int t;

// scanf("%d",&t);
// for(int i=1;i<=t;i++)
solve(1);


 
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
