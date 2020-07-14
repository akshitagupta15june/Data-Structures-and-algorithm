#include<iostream>
using namespace std;
class node{
public:
	int data;
	node* next;
	node(int d)
	{
		data=d;
		next=NULL;
	}

};
void insertAtTail(node*& head,int data)
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
void buildList(node*& head,int n)
{
	int count =0;
	while(count<n)
	{
		int data;
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
//function to merge two sorted linked lists
node* merge(node* head1,node* head2)
{
	if(head1==NULL)
		return head2;
	if(head2==NULL)
		return head1;
	node* c;
	if(head1->data < head2->data)
	{
		c=head1;
		c->next=merge(head1->next,head2);
	}
	if(head1->data > head2->data)
	{
		c=head2;
		c->next=merge(head1,head2->next);
	}
	return c;
}
node* midpoint(node* head)
{
	if(head==NULL || head->next==NULL)
		return head;
	node* slow=head;
	node* fast=head->next;
	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}
node* mergesort(node* head)
{
	if(head==NULL || head->next==NULL)
	{
		return head;
	}
	node* mid=midpoint(head);
	node* a=head;
	node* b=mid->next;
	mid->next=NULL;
	//recursive steps below
	a=mergesort(a);
	b=mergesort(b);
	node* c=merge(a,b);
	return c;

}

int main()
{
	int n;
	cin>>n;
	node* head=NULL;
	buildList(head,n);
    node* newHead=mergesort(head);
	printList(newHead);

	return 0;
}
