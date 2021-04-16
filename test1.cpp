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
#define sz 100001
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


int n;
vll v;
ll tree1[4*sz];
ll tree2[4*sz];

void update(int idx,int lo,int hi,int upidx,int val)
{
    if(upidx<lo||upidx>hi) return ;
    if(lo==hi)
    {
        tree1[idx]++;
        tree2[idx]+=val;
        return ;
    }

    int mid = (lo+hi)/2;
    int left = 2*idx+1;
    int right = 2*idx+2;
    update(left,lo,mid,upidx,val);
    update(right,mid+1,hi,upidx,val);
    tree1[idx]=tree1[left]+tree1[right];
    tree2[idx]=tree2[left]+tree2[right];

}

pll query(int idx,int lo,int hi,int qlo,int qhi)
{
    if(qlo>hi||qhi<lo) return {0,0};
    if(qlo<=lo&&qhi>=hi)
    return {tree1[idx],tree2[idx]};

    int mid = (lo+hi)/2;
    int left = 2*idx+1;
    int right = 2*idx+2;
    
    pll left_ans=query(left,lo,mid,qlo,qhi);
    pll right_ans=query(right,mid+1,hi,qlo,qhi);

    return { (left_ans.first+right_ans.first),(left_ans.second+right_ans.second) };

    
}


void solve(int t)
{

v.clear();

memset(tree1,0,sizeof tree1);
memset(tree2,0,sizeof tree2);
cin>>n;
ll mx=0;
for(int i=0;i<n;i++)
{
    int x;
    cin>>x;
    v.push_back(x);
    mx = maxx(mx,x);
}

ll ans=0;
for(int i=n-1;i>=0;i--)
{
    pll temp_ans = query(0,0,mx,v[i]+1,mx);
    // cout<<v[i]<<" "<<temp_ans.first<<" "<<temp_ans.second<<endl;
    ll temp_ans1=temp_ans.first+temp_ans.second;
    temp_ans1%=MOD;
    update(0,0,mx,v[i],temp_ans1);
    ans+=temp_ans1;
    ans%=MOD;
}

cout<<"Case "<<t<<": ";
cout<<(ans+n)%MOD<<endl;








}

 
 
int main()
{

// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
	
//int t;
//scanf("%d",&t);
int t;

scanf("%d",&t);
for(int i=1;i<=t;i++)
solve(i);


 
}


