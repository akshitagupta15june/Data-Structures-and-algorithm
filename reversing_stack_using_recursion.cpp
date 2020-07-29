#include <iostream>
#include<stack>
using namespace std;
void insertAtbottom(stack<int>&s,int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }
    int data=s.top();
    s.pop();
    insertAtbottom(s,x);
    s.push(data);
}
void reversestack(stack<int> &s)
{
    if(s.empty())
    {
        return;
    }
    int x=s.top();
    s.pop();
    reversestack(s);
    insertAtbottom(s,x);
}
int main(int argc, char **argv)
{
    stack<int>st;
	int n;
	cin>>n;
	int x;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		st.push(x);
	}
    reversestack(st);
    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}
