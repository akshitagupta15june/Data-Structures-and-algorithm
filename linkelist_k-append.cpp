#include <iostream>
using namespace std;


class node
{
    public:
    int data;
    node *next;

    node(int d)
    {
        data=d;
        next=NULL;
    }

};


void create(node *&head, int x )
{
    node *n=new node(x);

    if(head==NULL)
    {
        head=n;
        n->next=NULL;
    }
    else
    {
        node *temp=head;

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }

        temp->next=n;
        n->next=NULL;
    }
}


node *knode(node *head, int k)
{
    node *fast=head;
    node*slow=head;

    int c=1;

    while(c<k)
    {
        fast=fast->next;
        c++;
    }

node *prev;


    while(fast->next!=NULL)
    {
        prev=slow;
        fast=fast->next;
        slow=slow->next;
        //prev=prev->next;
    }

    fast->next=head;
    head=slow;
    prev->next=NULL;



return head;
}



void print(node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}



int main()
{

    int n1;
    node *head=NULL;

    int i,x,k;

    cin>>n1;
    for(i=0;i<n1;i++)
    {
       cin>>x;
       create(head,x);
    }

    cin>>k;
    k = k%n1;
    if(k==0){
        print(head);
    }else{
    node*final=knode(head,k);

    print(final);
    }

  

    return 0;
}
