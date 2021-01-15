#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
#define ld long double
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    ll x,y,x1,y1;
    double r;
    while(cin>>x>>y>>r && r>0.0)
    {
        ll n,c1,c2,ans=0;
        cin>>n;
        vector<pair<ll,ll>>v;
        while(n--)
        {
            cin>>x1>>y1;
            if((x-x1)*(x-x1)+(y-y1)*(y-y1)<=r*r)
            {
                v.push_back({x1-x,y1-y});
            }
        }
        for(ll i=0;i<v.size();i++)
        {
            c1=c2=0;
            for(ll j=0;j<v.size();j++)
            {
                if(v[i].first*v[j].second-v[j].first*v[i].second>=0)
                    c1++;
                if(v[i].first*v[j].second-v[j].first*v[i].second<=0)
                    c2++;
            }
            ans=max({ans,c1,c2});
        }
        cout<<ans<<endl;
    }

    return 0;
}
