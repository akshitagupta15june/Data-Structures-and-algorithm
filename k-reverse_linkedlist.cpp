#include<bits/stdc++.h>

using namespace std;

//const int n=5;

class node
{
   public:
     int data;
    node *next;
    node (int val)
    {
        data=val;
        next=NULL;
    }
};

/*node* linlist()
 {  int n;
 	cin>>n;
 	node *head=nULL,*tail=nULL;
 	while(n--)
 	{  int x;
 		cin>>x;
 		if(head==nULL)
         {
 		node* cur=new node(x);
 	          head=cur;
 	          tail=cur;
 	     }
 	     else
 	     {
 	     	node *cur=new node(x);
 	          tail->next=cur;
 	          tail=cur;
 	      }
 	 } 
 	 return head; 
 	}*/
 	 void print(node *head)
 	 {
 	 	node* cur=head;
 	 	while(cur!=NULL)
 	 	{
 	 		cout<<cur->data<<" ";
 	 	cur=cur->next;
 	 	}
 	 	cout<<endl;

 	 }
   
   node *reverse (node *head, int k)  
{  
    node* current = head;  
    node* next = NULL;  
    node* prev = NULL;  
    int count = 0;  
    
    while (current != NULL && count < k)  
    {  
        next = current->next;  
        current->next = prev;  
        prev = current;  
        current = next;  
        count++;  
    }  
      
  
    if (next != NULL)  
    head->next = reverse(next, k);  
    return prev;  
}

void insert_at_tail(node *&head,int x)
{
    if(head==NULL)
    {
        head=new node(x);
        return;
    }
    node* cur=head;
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    //node* nw=new node(x);
    //cur->next=nw;
    cur->next=new node(x);
    return;
    //return head;
}  
void buildlist(node *&head,int n)
{
int data;
while(n>0)
{
cin>>data;
insert_at_tail(head,data);
n--;
}
}
int main( )
{ 
	//node *head=linlist();
    node *head=NULL;
    int n,k;
    cin>>n>>k;
    buildlist(head,n);
       //  int k;
     //cin>>k;
    head=reverse(head,k);
    print(head);
  


	return 0;
}
