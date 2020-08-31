#include <iostream>
#include<algorithm>
#include<climits>
using namespace std;
int mincoins(int n,int coins[],int T,int dp[])
{
   if(n==0)
   {
       return 0;
   } 
   if(dp[n]!=0)
   {
       return dp[n];
   }
   int ans=INT_MAX;
   for(int i=0;i<T;i++)
   {
       if(n-coins[i]>=0)
       {
           int subpro=mincoins(n-coins[i],coins,T,dp);
           ans=min(ans,subpro+1);
       }
       
   }
   dp[n]=ans;
   return dp[n];
}
int mincoinsBU(int N,int coins[],int t)
{
    int dp[100]={0};
    for(int n=1;n<=N;n++)
    {
        
    for(int i=0;i<T;i++)
    {
        dp[n]=INT_MAX;
        if(n-coins[i]>=0)
        {
            int subprob=dp[n-coins[i]];
            dp[n]=min(dp[i],subprob+1);
        }
    }
    }
    return dp[N];
}
int main(int argc, char **argv)
{
	int n=5;
    int coins[]={1,2,3,4,5};
    int dp[100]={0};
    int t=sizeof(coins)/sizeof(int);
    //cout<<mincoins(n,coins,t,dp);
    cout<<mincoinsBU(N,coins,t)<<endl;
	return 0;
}
