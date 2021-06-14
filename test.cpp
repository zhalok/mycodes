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


//  * Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 


class Solution {

    int get_size(ListNode* node)
    {
        int size=0;
        while(node!=NULL)
        {
            size++;
            node=node->next;
        }
        return size;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     ListNode* temp_head = head;
     ListNode* prev_node = head;

     int size=get_size(head);
     int n=size-n;
     n++;
     int cnt=1;
     if(n==1) {
         head=head->next;
         return head;
     }
     while(temp_head!=NULL)
     {
        if(cnt==n)
        {
           prev_node->next=temp_head->next;
           break;
        }

        cnt++;
        prev_node=temp_head;
        temp_head=temp_head->next;
     } 

     return head;
        
    }
        

    };



  
     
      


// int main()
// {
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     Solution solution;
//     int n;
//     cin>>n;
//     vi vv;
//     for(int i=0;i<n;i++)
//     {
//       int x;
//       cin>>x;
//       vv.push_back(x);
//     }
//     int target;
//     cin>>target;
  

//    vector<vi> ans = solution.fourSum(vv,target);

//    for(int i=0;i<ans.size();i++)
//    {
//      for(int j=0;j<ans[i].size();j++) cout<<ans[i][j]<<" ";
//      cout<<endl;
//    }
    
    

// }
    
    

