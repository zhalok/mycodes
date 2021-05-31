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
#define sz 500001
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
pair<pll,pll> tree[8*sz];
vll v;
 
 
void build(int idx,int lo,int hi)
{
	// max sum total sum prefix suffix
	
    if(lo==hi) {
    	
    	tree[idx]={{v[lo],v[lo]},{v[lo],v[lo]}};
    	return ;
    	
	}
	
	int mid=(lo+hi)/2;
	int left=2*idx+1;
	int right=left+1;
	build(left,lo,mid);
	build(right,mid+1,hi);
	
    ll left_max=tree[left].ff.ff;
    ll left_sum=tree[left].ff.ss;
    ll left_pref=tree[left].ss.ff;
    ll left_suf=tree[left].ss.ss;
    
    ll right_max=tree[right].ff.ff;
    ll right_sum=tree[right].ff.ss;
    ll right_pref=tree[right].ss.ff;
    ll right_suf=tree[right].ss.ss;
	
    ll cross_max=left_suf+right_pref;
	
	ll par_max,par_sum,par_pref,par_suf;
   
     par_max=maxx(left_max,maxx(right_max,cross_max));
     par_sum=left_sum+right_sum;
     par_pref=maxx(left_pref,left_sum+right_pref);
     par_suf=maxx(right_suf,right_sum+left_suf);
    
    tree[idx]={{par_max,par_sum},{par_pref,par_suf}};
    
		
	
 } 
 
 
 
void update(int idx,int lo,int hi,int pos,int val)
{
	// max sum total sum prefix suffix
	if(lo>pos or hi<pos) return ;
	
    if(lo==hi) {
    	
    	tree[idx]={{val,val},{val,val}};
    	return ;
    	
	}
	
	int mid=(lo+hi)/2;
	int left=2*idx+1;
	int right=left+1;
	update(left,lo,mid,pos,val);
	update(right,mid+1,hi,pos,val);
	
    ll left_max=tree[left].ff.ff;
    ll left_sum=tree[left].ff.ss;
    ll left_pref=tree[left].ss.ff;
    ll left_suf=tree[left].ss.ss;
    
    ll right_max=tree[right].ff.ff;
    ll right_sum=tree[right].ff.ss;
    ll right_pref=tree[right].ss.ff;
    ll right_suf=tree[right].ss.ss;
 
	ll cross_max=left_suf+right_pref;
	ll par_max,par_sum,par_pref,par_suf;
	
	par_max=maxx(left_max,maxx(right_max,cross_max));
    par_sum=left_sum+right_sum;
    par_pref=maxx(left_pref,left_sum+right_pref);
    par_suf=maxx(right_suf,right_sum+left_suf);
    tree[idx]={{par_max,par_sum},{par_pref,par_suf}};
} 
 
 pair<pll,pll> query(int idx,int lo,int hi,int qlo,int qhi)
 {
    

    if(qhi<lo or qlo>hi) return {{-inf,-inf},{-inf,-inf}};
    
    if(qhi>=hi and qlo<=lo) return tree[idx];
 
	
	int mid=(lo+hi)/2;
	int left=2*idx+1;
	int right=left+1;
	
//	if(mid<=qlo) return query(right,mid+1,hi,qlo,qhi);
//	if(mid>=qhi) return query(left,lo,mid,qlo,qhi);
	
	
    pair<pll,pll> left_ans=query(left,lo,mid,qlo,qhi);
	pair<pll,pll> right_ans=query(right,mid+1,hi,qlo,qhi);
	
    ll left_max=left_ans.ff.ff;
    ll left_sum=left_ans.ff.ss;
    ll left_pref=left_ans.ss.ff;
    ll left_suf=left_ans.ss.ss;
    
    ll right_max=right_ans.ff.ff;
    ll right_sum=right_ans.ff.ss;
    ll right_pref=right_ans.ss.ff;
    ll right_suf=right_ans.ss.ss;
	
    ll cross_max=left_suf+right_pref;
	
	ll par_max,par_sum,par_pref,par_suf;
	
    par_max=maxx(left_max,maxx(right_max,cross_max));
    par_sum=left_sum+right_sum;
    par_pref=maxx(left_pref,left_sum+right_pref);
    par_suf=maxx(right_suf,right_sum+left_suf);
    
    return {{par_max,par_sum},{par_pref,par_suf}};
 
	
 	
 	
 }
