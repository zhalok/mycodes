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
    int gridd[50][50];
    set<int>s;

    bool isperfect(int sr,int er,int sc,int ec)
    {
      s.clear();
  

      for(int i=sr;i<=er;i++)
      {
        int sum =0;
          for(int j=sc;j<=ec;j++)
          sum+=gridd[i][j];
          s.insert(sum);

      }

      for(int i=sc;i<=ec;i++)
      {
        int sum = 0;
        for(int j=sr;j<=er;j++)
        sum+=gridd[j][i];
        s.insert(sum);
      }

      int diagonal_sum1=0;
      int digaonal_sum2=0;

      int i=sr;
      int j=sc;
      while(i<=er&&j<=ec)
      {
        diagonal_sum1+=gridd[i][j];
        i++;
        j++;
      }

      s.insert(diagonal_sum1);

      i=er;
      j=sc;

      while(i>=sr&&j<=ec)
      {
        digaonal_sum2+=gridd[i][j];
        i--;
        j++;
      }

      s.insert(digaonal_sum2);
      
      if(s.size()==1) return true;
      else return false;
     
      
    }

    int largestMagicSquare(vector<vector<int>>& grid){
            
        for(int i=0;i<grid.size();i++)
        {
          for(int j=0;j<grid[i].size();j++)
          gridd [i][j]=grid[i][j];
        }

        int ans =0;
        
        for(int k=1;k<=min(grid.size(),grid[0].size());k++)
        {
            for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[i].size();j++)
            {
              int sr=i;
              int er=i+k-1;
              int sc=j;
              int ec=j+k-1;
              if(er<grid.size()&&ec<grid[0].size()){
               

              if(isperfect(sr,er,sc,ec))
              {
                 ans = max(ans,k);
              }

              }


            }
        }

        return ans;

    }

    };



  
     
      


// int main()
// {
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     Solution solution;
//     int n,m;
//     cin>>n>>m;
//     vector<vi>v;

//     for(int i=0;i<n;i++)
//     {
//       vi temp;
//       for(int j=0;j<m;j++)
//       {
//         int x;
//         cin>>x;
//         temp.push_back(x);
//       }
//       v.push_back(temp);
//     }

//     cout<<solution.largestMagicSquare(v)<<endl;
    

// }
    
    

