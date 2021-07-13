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
#define sz 4002
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

int n,m;

ll adjmat[4002][4002];

bool visited[4002];

int par[4002];

void dfs(int node)
{
    visited[node]=true;
  
    for(int i=0;i<=4001;i++)
    if(adjmat[node][i]>0&&visited[i]==false)
    {
        par[i]=node;
        dfs(i);
    }
}



ll check_connection(int s,int t)
{
   memset(par,-1,sizeof par);
   memset(visited,false,sizeof visited);

   dfs(s);
   
   ll mn = inf ;

   int cur = t;

   if(par[cur]==-1){

//    cout<<"No path found"<<endl;
   return -1;

   }

   
   
   vi path;
   
   while(par[cur]!=-1)
   {
       
       path.push_back(cur);
       mn = minn(mn,adjmat[par[cur]][cur]);
       cur = par[cur];
       
   }

//    cout<<"Path found"<<endl;
//    path.push_back(cur);
//    reverse(all(path));
//    for(auto x:path) cout<<x<<" ";
//    cout<<endl;




   cur = t;

   while(par[cur]!=-1)
   {
       adjmat[par[cur]][cur]-=mn;
       adjmat[cur][par[cur]]+=mn;
       cur = par[cur];
   }

   return mn;

   
   
}




ll ford_fulkerson(int s,int t)
{
    ll result=0;
   
    while(1)
    {
       ll temp_res = check_connection(s,t);
       if(temp_res==-1) break;
       result+=temp_res;
    }

    return result;
}

ll main_adjmat[4002][4002];

int redirect(int cap,int node,int t)
{
    ll ans =0;

   for(int i=0;i<=4001;i++){
   
   ll temp;
   if(adjmat[node][i]>0){

   temp=check_connection(i,t);
  
   if(temp!=-1) { 
   ans++; 
   adjmat[node][i]--;
   adjmat[i][node]++;
   }
  
   if(ans==cap) break;

   }

   }

   return cap-ans;
   

}


void solve()
{
   memset(main_adjmat,0,sizeof main_adjmat);
    
   int n,m,k;
   cin>>n>>m>>k;
   
   while(k--)
   {
       int x,y;
       cin>>x>>y;
       main_adjmat[x][y+n]=1;
   }



   
   for(int i=1;i<=n;i++)
   main_adjmat[0][i]=1;

   for(int i=1;i<=m;i++)
   cin>>main_adjmat[i+n][4001];

  

   for(int i=0;i<=4001;i++)
   for(int j=0;j<=4001;j++)
   adjmat[i][j]=main_adjmat[i][j];
   

 

   ll mx_flow=ford_fulkerson(0,4001);

   

   

   int z;
   cin>>z;

   while(z--)
   {
    
      cout<<mx_flow<<endl;
      int p,q;
      cin>>p>>q;
      if(adjmat[p+n][4001]>=q) adjmat[p+n][4001]-=q;
      else{

         
          int cap = q-adjmat[p+n][4001];
          adjmat[p+n][4001]=0;
          adjmat[4001][p+n]-=cap;
          int temp_ans=redirect(cap,p+n,4001);
          mx_flow-=temp_ans;
         
          }
      
   }
  



     
}



int main()
{

// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);

ios_base::sync_with_stdio(false);
cin.tie(NULL);

solve();


}