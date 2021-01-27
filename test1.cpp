#include<bits/stdc++.h>
using namespace std;
list<int>li;

void solve(int t)
{
    li.clear();
    int n,m;
    cin>>n>>m;
    cout<<"Case "<<t<<":"<<endl;
    for(int i=0;i<m;i++)
    {
        string cmd;
        cin>>cmd;
        if(cmd=="pushLeft"||cmd=="pushRight")
        {
            int x;
            cin>>x;
            if(li.size()<n)
            {
                if(cmd=="pushLeft")
                { cout<<"Pushed in left: "<<x<<endl;
                li.push_front(x);}
                else if(cmd=="pushRight"){
                    cout<<"Pushed in right: "<<x<<endl;
                    li.push_back(x);}
            }
            else cout<<"The queue is full"<<endl;
        }
        else if(cmd=="popLeft"||cmd=="popRight")
        {
            if(li.size()>0)
            {
            if(cmd=="popLeft")
            {
                cout<<"Popped from left: "<<li.front()<<endl;
                li.pop_front();
            }
            else if(cmd=="popRight"){
                cout<<"Popped from right: "<<li.back()<<endl;
                li.pop_back();
            }
            }else cout<<"The queue is empty"<<endl;
        }
            
        
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    solve(i);

}