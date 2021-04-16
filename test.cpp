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
#define sz 200001
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

int n,q;
int tree1[4*sz];
int tree2[4*sz];

void update1(int idx,int lo,int hi,int upidx,int val)
{
	if(upidx<lo||upidx>hi) return ;
	if(lo==hi)
	{
		tree1[idx]=val;
		return ;
	}

	int mid = (lo+hi)/2;
	int left = 2*idx+1;
	int right = 2*idx+2;
	
	update1(left,lo,mid,upidx,val);
	update1(right,mid+1,hi,upidx,val);
	tree1[idx]=tree1[left]+tree1[right];
}

void update2(int idx,int lo,int hi,int upidx,int val)
{
	if(upidx<lo||upidx>hi) return ;
	if(lo==hi)
	{
		tree2[idx]=val;
		return ;
	}

	int mid = (lo+hi)/2;
	int left = 2*idx+1;
	int right = 2*idx+2;
	
	update2(left,lo,mid,upidx,val);
	update2(right,mid+1,hi,upidx,val);

	tree2[idx]=tree2[left]+tree2[right];
}

int query1(int idx,int lo,int hi,int qlo,int qhi)
{
	if(qlo>hi||qhi<lo) return 0;
	if(qlo<=lo&&qhi>=hi) return tree1[idx];
	int mid = (lo+hi)/2;
	int left = 2*idx+1;
	int right = 2*idx+2;
	return query1(left,lo,mid,qlo,qhi)+query1(right,mid+1,hi,qlo,qhi);

}

int query2(int idx,int lo,int hi,int qlo,int qhi)
{
	if(qlo>hi||qhi<lo) return 0;
	if(qlo<=lo&&qhi>=hi) return tree2[idx];
	int mid = (lo+hi)/2;
	int left = 2*idx+1;
	int right = 2*idx+2;
	return query2(left,lo,mid,qlo,qhi)+query2(right,mid+1,hi,qlo,qhi);

}




ll dp[10][200001];

ll get_ans(int d,int m)
{
	if((10-d)>m) return 0;
	if(dp[d][m]!=-1) return dp[d][m];
    return dp[d][m]=(1+get_ans(1,(m-(10-d)))%MOD+get_ans(0,m-(10-d))%MOD)%MOD;
}


void solve(int t)
{

int n;
cin>>n;

vector<string>v;
vector<pii>points;

for(int i=0;i<n;i++)
{
	string s;
	cin>>s;
    v.push_back(s);
}

for(int i=0;i<v.size();i++)
for(int j=0;j<v[i].size();j++)
if(v[i][j]=='*')
points.push_back({i,j});

// sort(all(points));

pii point1;
pii point2;

if(points[0].first==points[1].first)
{
	if(points[0].first==n-1)
	{
	point1={points[0].first-1,points[0].second};
	point2={points[1].first-1,points[1].second};
	}
	else {
		point1={points[0].first+1,points[0].second};
		point2={points[1].first+1,points[1].second};
		}
}
else if(points[0].second==points[1].second)
{
	if(points[0].second==n-1)
	{
	point1={points[0].first,points[0].second-1};
	point2={points[1].first,points[1].second-1};
	}
	else {
	point1={points[0].first,points[0].second+1};
	point2={points[1].first,points[1].second+1};
	}
}
else{

 point1={points[0].first,points[1].second};
 point2={points[1].first,points[0].second};

}

v[point1.first][point1.second]='*';
v[point2.first][point2.second]='*';

for(auto x:v) cout<<x<<endl;
cout<<endl;

	





}

int main()
{

freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
	
//int t;
//scanf("%d",&t);
int t;
// memset(dp,-1,sizeof dp);
scanf("%d",&t);
for(int i=1;i<=t;i++)
solve(i);

}
