#include<bits/stdc++.h>
using namespace std;
using namespace std;
#define zhalok Zhalok
#define inf 1000000
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
#define sz 10001
#define ub upper_bound
#define lb lower_bound
#define all(v) v.begin(),v.end()
#define eps 1e-8
#define pi acos(-1.0)


class Solution {
public:
    map<string,bool>mp;
    map<int,bool>flag;
    string t;
    string ss;

    bool check(int i,int j,int seg)
    {
        vector<string>temp;
        for(int k=i;k<=j;k+=seg)
        {
            if(flag[k])
            {
                string temps;
                for(int x=k;x<k+seg;x++)
                temps+=ss[x];
                temp.push_back(temps);
                // cout<<i<<" "<<j<<endl;
                // cout<<temps<<endl;
            
            }
            else return false;

        }

        sort(all(temp));
        string tempss;
        for(auto x:temp) tempss+=x;
        // cout<<tempss<<endl;
        if(tempss==t)
        return true;
        else return false;
        
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        
        sort(all(words));
        // for(auto x:words) cout<<x<<endl;
        
        for(auto x:words){ 
            mp[x]=true;
            t+=x;
        }
        ss=s;

        
        

        int i=0;
        int j=words[0].size()-1;
       
        while(j<s.size())
        {
            string temp;
            for(int k=i;k<=j;k++)
            temp+=s[k];
            if(mp[temp])
            flag[i]=true;
            i++;
            j++;
        }

        

        int total_size=0;
        for(auto x:words) total_size+=x.size();
        // cout<<total_size<<endl;
       
        i=0;
        j=total_size-1;

        vi ans ;

        while(j<s.size())
        {
            if(check(i,j,words[0].size()))ans.push_back(i);
            i++;
            j++;

        }

        return ans;
         


    }
};
     
      


int main()
{
    // cout<<"HEllo world"<<endl;
    //gu
    int m;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vi v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);

        
    }

    for(auto x: v)cout<<x<<endl;
    
    // Solution solution;

    // string s;
    // vector<string>v;

    // cin>>s;
    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++)
    // {
    //     string s;
    //     cin>>s;
    //     v.push_back(s);
    // }

    // vi ans = solution.findSubstring(s,v);
    // for(auto x:ans) cout<<x<<" ";
    // cout<<endl;
    

}
    
    

