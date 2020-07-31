#include <iostream>
using namespace std;
class queue{
    int *arr;
    int f,r,cs,ms;
public:
     queue(int ds=5)
     {
         arr=new int[ds];
         cs=0;
         ms=ds;
         f=0;
         r=ms-1;
     }
     bool full()
     {
         return cs==ms;
     }
     bool empty()
     {
         return cs==0;
     }
     void push(int data)
     {
         if(!full())
         {
             r=(r+1)%ms;
             arr[r]=data;
             cs++;
         }
         
     }
     void pop()
     {
         if(!empty())
         {
             f=(f+1)%ms;
             cs--;
         }
         
     }
     int front(){
         return arr[f];
     }
     ~queue()
     {
         if(arr!=NULL)
         {
             delete [] arr;
             arr=NULL;
         }
     }
};
int main(int argc, char **argv)
{
	queue q;
    for(int i=1;i<=6;i++)
    {
        q.push(i);
    }
    q.push(7);
    q.push(8);
    q.pop();
    for(int i=1;i<=6;i++)
    {
        cout<<q.front();
    }
	return 0;
}
