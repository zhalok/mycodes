    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define ld long double
    int main()
    {
        freopen("input.txt","r",stdin);
        freopen("ouput.txt","w",stdout);
    	  ld x,y;
          ll x1,y1,x2,y2,x3,y3,a1,b1,c1,a2,b2,c2;
        while(~scanf("%lld%lld%lld%lld%lld%lld",&x1,&y1,&x2,&y2,&x3,&y3))
        {
     
     
            a1=-2*(x1-x2);
            b1=-2*(y1-y2);
            c1=(x1*x1+y1*y1)-(x2*x2+y2*y2);
            a2=-2*(x2-x3);
            b2=-2*(y2-y3);
            c2=(x2*x2+y2*y2)-(x3*x3+y3*y3);
            if(a1*b2-a2*b1==0)
                cout<<"Impossible"<<endl;
            else
            {
                if((b1*c2-b2*c1)==0) x=0;
                else 
                x=1.0*(b1*c2-b2*c1)/(a1*b2-a2*b1);
                if((c1*a2-c2*a1)==0) y=0;
                else 
                y=1.0*(c1*a2-c2*a1)/(a1*b2-a2*b1);
                 cout<<fixed<<setprecision(10)<<x<<" "<<y<<endl;
                
            }
        }
        return 0;
    }
     