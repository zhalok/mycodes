#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int nod(int n);

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    vector<pii>v;
    for(int i=1;i<=1000;i++)
    {
        int d=nod(i);
        v.push_back({d,-i});
    }
    
    sort(v.begin(),v.end());

	for(auto x:v) cout<<x.first<<" "<<-x.second<<endl;
	
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        int n;
        cin>>n;
        cout<<"Case "<<t<<": ";
        cout<<-v[n-1].second<<endl;
    }
	


}

int nod(int n)
{
   int cnt=0;
    for(int i=1;i*i<=n;i++)
    if(n%i==0) cnt+=2;
    int temp=sqrt(n);
    if(temp*temp==n) cnt--;
    return cnt;
       

}