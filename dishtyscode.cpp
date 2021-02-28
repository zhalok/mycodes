#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define dbl(xz,zx) setprecision(zx)<<fixed<<xz
#define pb push_back
#define pi acos(-1.0)

#ifndef ONLINE_JUDGE // it works locally
#define here cout<<"here"<<endl;
#define print(axr,xx)for(int i=0;i<xx;i++)cout<<axr[i]<<" \n"[i==xx-1];
#define dbg(xxa) cout<<""#xxa""<<" is "<<xxa<<endl;
#define fastio ;
#else // when being compiled in an on line judge
#define here ;
#define print(axr,xx) ;
#define dbg(xxa) ;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#endif

#define YES() cout<<"Yes"<<endl;
#define NO() cout<<"No"<<endl;
#define infL 0x3f3f3f3f3f3f3f3fLL
#define inf 1<<30
#define mod 1000000007
#define sz 100010
int k;

struct node
{
    node *next[2];
    int val;
    node()
    {
        val=0;
        next[0]=next[1]=NULL;
    }

}*root;


void insert_in_trie(int n)
{
    node *cur=root;
    for(int i=31; i>=0; i--)
    {
        bool now=n&(1<<i);
        if(cur->next[now]==NULL)
        {
            cur->next[now]=new node();
        }
        cur=cur->next[now];
        cur->val++;

    }

}

int search_in_trie(int n)
{
    node *cur=root;
    int res=0;
    for(int i=31; i>=0; i--)
    {
        if(cur == NULL)
            break;
        bool now=n&(1<<i);
        bool K=k&(1<<i);

        if(now==K)
        {
            if(K)
            {
                if(cur->next[1]!=NULL)
                {
                    res+=cur->next[1]->val;
                }
            }
            cur=cur->next[0];
        }
        else
        {
            if(K)
            {
                if(cur->next[0]!=NULL)
                {
                    res+=cur->next[0]->val;
                }
            }
            cur=cur->next[1];
        }


    }

    return res;
}


int main()
{
    fastio
    int T;
    T=1;
    cin>>T;

    while(T--)
    {
        int i,j,m,n,l;
        ll res=0,ans=0;
        cin>>n>>k;
        root = new node();
        insert_in_trie(0);
        for(i=0; i<n; i++)
        {
            cin>>m;
            ans^=m;

            res+=search_in_trie(ans);
            insert_in_trie(ans);

        }

        cout<<res<<endl;


    }
}