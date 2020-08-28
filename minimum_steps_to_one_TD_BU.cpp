#include <iostream>
#include<climits>
#include<algorithm>
using namespace std;
int minsteps(int n,int dp[])
{
    //top down approach
    if(n==1)
    {
        return 0;
    }
    if(dp[n]!=0)
    {
        return dp[n];
    }
    int op1,op2,op3;
    op1=op2=op3=INT_MAX;
    if(n%3==0)
    {
        op1=minsteps(n/3,dp)+1;
    }
    if(n%2==0)
    {
        op2=minsteps(n/2,dp)+1;
    }
    op3=minsteps(n-1,dp)+1;
    int ans=min(min(op1,op2),op3);
    return dp[n]=ans;
}
int minstepBU(int n)
{
    int dp[100]={0};
    dp[1]=0;
    for(int i=2;i<=n;i++)
    {
        int op1,op2,op3;
        op1=op2=op3=INT_MAX;
        if(n%3==0)
        {
            op1=dp[i/3];
        }
        if(n%2==0)
        {
            op2=dp[i/2];
        }
        op3=dp[i-1];
        dp[i]=min(op1,op2,op3)+1;
    }
    return dp[n];
}
int main(int argc, char **argv)
{
	int n;
    cin>>n;
    int dp[100]={0};
    cout<<minsteps(n,dp)<<endl;
    cout<<minstepBU(n)<<endl;
	return 0;
}
