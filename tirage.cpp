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




class Patient{


    private:
    string name;
    string priority;
    string arrival;

    
    Patient(string ptname,string ptpriority,string ptarrival){
        name=ptname;
        priority=ptpriority;
        arrival=ptarrival;

    }   

    public:
    string to_string()
    { 

        string str="pri="+priority+","+"arrive="+arrival;
        return str;
         
    }
    

};

class patientpriorityqueue{

   map<string,int>mp;
   patientpriorityqueue()
   {
       mp["immediate"]=0;
       mp["emergency"]=15;
       mp["urgent"]=30;
       mp["minimal"]=120;
   }


priority_queue<pair<int,Patient>>pq;
   
   public:
   void add(string priority,Patient patient){
    
    pq.push({mp[priority],patient});

   }

   Patient peek()
   {
       Patient patient = pq.top().second;
       return patient;
   }

   Patient remove()
   {
       Patient patient = pq.top().second;
       pq.pop();
       return patient;
   }

   
};



