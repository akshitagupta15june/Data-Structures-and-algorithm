#include<iostream>
using namespace std;
class node{
public:
	long long int data;
	node* next;
	node(long long int d)
	{
		data=d;
		next=NULL;
	}

};
void insertAtTail(node*& head,long long int data)
{
	if(head==NULL)
	{
		head=new node(data);
		return;
	}
	node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	node* n=new node(data);
	temp->next=n;
	
}
void buildList(node*& head,long long int n)
{
	long long int count =0;
	while(count<n)
	{
		long long int data;
		cin>>data;
		insertAtTail(head,data);
		count++;

	}
}
void printList(node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}
void sorteddesc(node*&head)
{
    node *q,*p;
    q=head;
    long long int data;
    while(q!=NULL)
    {
       p=q->next;
       while(p!=NULL)
         {
         if(q->data<p->data)
             {
                 data=q->data;
                 q->data=p->data;
                 p->data=data;
             }
         p=p->next;
         }
         q=q->next;
    }
}
void sortedinc(node*&head)
{
    node *q,*p;
    q=head;
    long long int data;
    while(q!=NULL)
    {
       p=q->next;
       while(p!=NULL)
         {
         if(q->data>p->data)
             {
                 data=q->data;
                 q->data=p->data;
                 p->data=data;
             }
         p=p->next;
         }
         q=q->next;
    }
}
bool find_triplet(node*head1,node*head2,node*head3,long long int target)
{
    node*a=head1;
    while(a!=NULL)
    {
        node*b=head2;
        node*c=head3;
        while(b!=NULL && c!=NULL)
        {
            long long int sum = a->data + b->data + c->data;  
            if (sum == target)  
            {  
            cout<< a->data << " " <<  
                                b->data << " " << c->data;  
			return true;
            
            }
            else if (sum < target)  
            {
                b = b->next; 
            }
                 
            else 
            {
                c = c->next;
            }
  
        }
        a=a->next;
    }
    return false;
}
int main()
{
	long long int n1,n2,n3;
	cin>>n1>>n2>>n3;
	node* head1=NULL;
    node* head2=NULL;
    node* head3=NULL;
	buildList(head1,n1);
    buildList(head2,n2);
    buildList(head3,n3);
    long long int target;
    cin>>target;
    sortedinc(head2);
    sorteddesc(head3);
    bool succ=find_triplet(head1,head2,head3,target);
    if(succ=true)
    {
        bool liv=true;
    }
	return 0;
}
