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
int main(int argc, char **argv)
{
	int n=15;
    int coins[]={1,7,10};
    int dp[100]={0};
    int t=sizeof(coins)/sizeof(int);
    cout<<mincoins(n,coins,t,dp);
	return 0;
}
