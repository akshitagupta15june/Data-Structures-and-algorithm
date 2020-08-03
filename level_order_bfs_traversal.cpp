#include <iostream>
#include<stack>
using namespace std;
void stock_span(long long int *price,long long int n,long long int *span)
{
   stack<long long int>s;
   s.push(0);
   span[0]=1; 
   for(int i=1;i<=n-1;i++)
   {
       int cur_price=price[i];
       while(!s.empty() and price[s.top()]<=cur_price)
       {
           s.pop();
           
       }
       if(!s.empty())
       {
           int prev_high=s.top();
       span[i]=i-prev_high;
       }
       else
       {
           span[i]=i+1;
       }
       s.push(i);
       
   }
}
int main(int argc, char **argv)
{
    long long int n;
	cin>>n;
	long long int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	long long int newed[n];
	stock_span(arr,n,newed);
    for(int i=0;i<n;i++)
    {
        cout<<newed[i]<<" ";
    }
    cout<<"END";
	return 0;
}
