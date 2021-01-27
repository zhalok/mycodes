#include<bits/stdc++.h>//m
typedef long long int ll;
using namespace std;
#define sz 10003
int arr[103];
double brr[103],dp[sz];
int main()
{
   int t;
   scanf("%d",&t);
   for(int cs=1;cs<=t;cs++)
   {
    int n,sum=0;
    double p;
    scanf("%lf %d",&p,&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %lf",&arr[i],&brr[i]);
        sum+=arr[i];
    }
  //  printf("%lf\n",p );
    dp[0]=0.0;
    for(int i=1;i<=sum;i++)
    {
        dp[i]=1.0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=sum;j>=1;j--)
        {
            int a=j-arr[i];
            if(a>=0)
                dp[j]=min(dp[j],dp[a]+(1-dp[a])*brr[i]);
        }
    }
    int ans=0;
    for(int i=1;i<=sum;i++)
    {
     if(dp[i]<p)
        ans=i;
    }
    printf("Case %d: %d\n",cs,ans);
   }
}