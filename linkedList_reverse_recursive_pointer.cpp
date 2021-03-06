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
node* reverse(node*head)
{
    if(head->next==NULL||head==NULL)
    {
        return head;
    }
    node*smallhead=reverse(head->next);
    node*c=head;
    c->next->next=c;
    c->next=NULL;
    return smallhead;
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
    head=reverse(head);
    print(head);
    cout<<endl;
    //node*m=midpoint(head);
    //cout<<m->data;
    
}
