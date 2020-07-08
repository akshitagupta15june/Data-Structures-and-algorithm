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
//passing head by reference
void insert_At_head(node *&head,int data)
{
    node *n=new node(data);
    n->next=head;
    head=n;
}
//pass by value no change in head
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"-->";
        temp=temp->next;
    }
    cout<<endl;
}
int main(int argc, char **argv)
{
	node *head=NULL;
	insert_At_head(head,5);
    insert_At_head(head,7);
    insert_At_head(head,9);
    print(head);
}
