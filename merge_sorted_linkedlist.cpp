#include <iostream>
using namespace std;


class node{
public:
	int data;
	node*next;

	node(int d){
		data=d;
		next=NULL;
	}
};

void insertAtTail(node*&head,int data){

	if(head==NULL){
		head=new node(data);
		return;
	}
	node*tail=head;
	while(tail->next!=NULL){
		tail=tail->next; //last node of the linked list
	}
	tail->next=new node(data);
	return ;
}

void buildList(node*&head){
   int n;
	cin>>n;

	while(n>0){
		int data;
		cin>>data;
		insertAtTail(head,data);
		n--;
	}
}

void print(node*head){
	if(head == NULL){
		return;
	}
	cout<<head->data<<" ";
	print(head->next);
}

node* merge(node*a,node*b){
	if(a==NULL){
		return b;
	}else if(b==NULL){
		return a;
	}
	node*c;
	//compare elemnt a and b
	if(a->data <= b->data){
		c=a;
		c->next=merge(a->next,b);//here a->next means that a->next ids the remaining part and b and then again the function will 
	}else if(a->data>b->data){
		c=b;
		c->next=merge(a,b->next);//here if c doenot point to a then the smallest element points is in the b node
	}
	return c;
}

int main(){
	 int t;
	cin>>t;
	while (t--){
		int n;
    		//cin>>n;
		node *head = NULL;
		node *head2 = NULL;
		buildList(head);
    		//cin>>n;
		buildList(head2);
		node* newhead = merge(head,head2);
		print(newhead);
		// print(head2);
		cout<<endl;
	}
	return 0;
}
