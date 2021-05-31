#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<vector>
#include <utility>
using namespace std;
#define zhalok Zhalok
#define inf 1000000000.0
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
#define eps 1e-2
#define pi acos(-1.0)

vpll upper;
vpll lower;
vpll convexhull;
vpll points;
pll leftmost;
pll rightmost;


void total_convexhull();
void upper_convexhull();
void lower_convexhull();
int check_sidde();
int check_rotation();


void solve()
{




}

int main()
{
    solve();
}


void total_convexhull()
{

    sort(points.begin(),points.end());
     leftmost=points[0];
     rightmost=points[points.size()-1];
    convexhull.push_back(leftmost);
    convexhull.push_back(rightmost);
    for(int i=0;i<points.size();i++)
    if(check_sidde(leftmost,rightmost,points[i])==1) upper.push_back(points[i]);
    else if(check_sidde(leftmost,rightmost,points[i])==-1)
    lower.push_back(points[i]);

    upper_convexhull();
    lower_convexhull();




}

void upper_convexhull()
{

vector<pll>st;
st.push_back(leftmost);
st.push_back(upper[0]);
for(int i=1;i<upper.size();i++)
{
    pll a=st[st.size()-1];
    pll b=st[st.size()-2];
    pll c=upper[i];
    if(check_rotation(b,a,c)>0) convexhull.push_back(a);
    else st.pop_back();
    st.push_back(upper[i]);

}

pll a=st[st.size()-1];
pll b=st[st.size()-2];
if(check_rotation(b,a,rightmost)>0) convexhull.push_back(a);




}

void lower_convexhull()
{
 vector<pll>st;
st.push_back(leftmost);
st.push_back(upper[0]);
for(int i=1;i<lower.size();i++)
{
    pll a=st[st.size()-1];
    pll b=st[st.size()-2];
    pll c=upper[i];
    if(check_rotation(b,a,c)>0) convexhull.push_back(a);
    else st.pop_back();
    st.push_back(lower[i]);

}

pll a=st[st.size()-1];
pll b=st[st.size()-2];
if(check_rotation(b,a,rightmost)>0) convexhull.push_back(a);

}

int check_sidde(pll p1,pll p2,pll p3)
{
	ll x1=p1.first;
	ll y1=p1.second;
	ll x2=p2.first;
	ll y2=p2.second;
	ll x3=p3.first;
	ll y3=p3.second;

    ll ans=(x3-x1)*(y1-y2)-(y3-y1)*(x1-x2);
	if(ans>0) return 1;
	else if(ans<0)return -1;
    else return 0;

}

int check_rotation(pll a,pll b,pll c)
{

    ll x1,y1;
    x1=a.first;
    y1=a.second;
    ll x2,y2;
    x2=b.first;
    y2=b.second;
    ll x3,y3;
    x3=c.first;
    y3=c.second;
    ll rotation=(x3-x2)*(x2-x1)+(y3-y2)*(y2-y1);
    if(rotation>0) return 1;
    else if(rotation==0) return 0;
    else return -1;


}