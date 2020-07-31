#include <iostream>
#include<list>
using namespace std;
class queue{
    int cs;
    list<int>l;
public:
    queue()
    {
        cs=0;
    }
    bool isempty()
     {
         return cs==0;
     }
     void push(int data)
     {
         l.push_back(data);
         cs=cs+1;
     }
     void pop(){
         if(!isempty())
         {
             cs--;
             l.pop_front();
         }
     }
     int front(){
         return l.front();
     }
};
int main(int argc, char **argv)
{
	queue q;
    for(int i=1;i<=10;i++)
    {
        q.push(i);
    }
    while(!q.isempty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
	return 0;
}
