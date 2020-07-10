#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node* next;
    //CONSTRUCTOR
    node(int d)
    {
        data=d;
        next=NULL;
    }
};
void insert_At_tail(node*&head,int data)
{
    if(head==NULL)
    {
        head=new node(data);
        return;
    }
    node*tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    tail->next=new node(data);
    return;
}
void reverse(node*&head)
{
    node*c=head;
    node*p=NULL;
    node*n;
    while(c!=NULL)
    {
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    head=p;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void buildlist(node*&head,int n)
{
    int data;
    int j=0;
    while(j<n)
    {
        cin>>data;
        insert_At_tail(head,data);
        j++;
    }
}
int main(int argc, char **argv)
{
	node *head=NULL;
    int n;
    cin>>n;
    buildlist(head,n);
    reverse(head);
    print(head);
    
}
