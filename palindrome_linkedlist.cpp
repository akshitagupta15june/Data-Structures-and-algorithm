#include<bits/stdc++.h>	
using namespace std;

class node{
	    
	    public:
	    node *next=NULL;
	    node *prev=NULL;
	    int data;
	    
	    node(int d){
	        
	        data=d;
	        
	    }
		void  insert(node*&head,node*&tail,int d){
	        
	        node*newnode=new node(d);
	        
	        if(head==NULL){
	            head =tail=newnode;
	            return;
	        }
	        
	        tail->next=newnode;
	        newnode->prev = tail;
	        tail=newnode;
 
	    }
	 
	};
int main() {
	
node*head=NULL;
node*tail=NULL;
int n;

cin>>n;
int i=n;
while(i>0){
 
 int d;
 cin>>d;
 //cout<<d<<endl;
 
 head->insert(head,tail,d);	///YOU CAN ALL THE MEMBER FUNCTION ONLY BY A OBJECT/POINTER OF THAT CLASS.
 ///In this ques, insert need not be member function of class

    i--;
}

//cout<<head->data<<" "<<tail->data;

while(tail!=head ){
    
    if(head->data==tail->data){
        head=head->next;
        tail=tail->prev;
    }
    
    else{
        cout<<"false";
        return 0; 
       
    }
   
}
 cout<<"true";	
}
