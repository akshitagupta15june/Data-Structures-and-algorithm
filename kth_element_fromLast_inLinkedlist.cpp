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
/*node* reverse(node*head)
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
}*/
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
node* kth_node(node *head,int k)  
{  
    node *slow_ptr = head;  
    node *fast_ptr = head;
    int j=1;
    while(j<=k)
    {
        fast_ptr=fast_ptr->next;
        j++;
    }
    while(fast_ptr!=NULL)
    {
        fast_ptr=fast_ptr->next;
        slow_ptr=slow_ptr->next;
    }
  return slow_ptr;
}  
void buildlist(node*&head,int data)
{

        insert_At_tail(head,data);
}
int main(int argc, char **argv)
{
	node *head=NULL;
    int data;
    for(int i=0;;i++)
    {
        cin>>data;
        if(data==-1)
        {
            break;
        }
            
	    buildlist(head,data);
    }
    int k;
    cin>>k;
    node*m=kth_node(head,k);
    cout<<m->data;
    
    
}
