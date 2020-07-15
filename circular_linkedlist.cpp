#include <iostream>
using namespace std;
long int cycle = 0;
class Node{
public:
    long int data;
    Node * next;   
    
    Node(long int num){
        data = num;
        next = NULL;   
    }
};
void addToBack(Node* &head, Node* nodeToAdd){
   int flag = 0;
     Node*save;
    if (head == NULL){
        head = nodeToAdd;
        return;
    }
   Node * temp = head;
   while(temp->next!=NULL){
       if(temp->data==nodeToAdd->data)
       {
           flag =1;
           save  = temp;
       }
       temp = temp->next;
   }
   if(flag ==0){
   temp->next= nodeToAdd;}
   else {
       temp->next = save;
       cycle = 1;
   }
    
}

void print(Node* head){
    Node * tmp = head;
    while(tmp != NULL){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
Node* takeInput(){
    int num;
    Node * head = NULL;

    while(cin>>num && num!=-1){
        if(cycle ==1)
        {
            break;
        }
        Node * newNode = new Node(num);
        addToBack(head, newNode);
    }
    return head;
}


Node* detectcycle(Node * head)
{
   Node* sp = head;
   Node* fp = head;
   while(sp!=NULL)
   {  
       sp= sp->next;
       fp = fp->next->next;
       if(sp==fp)
       {
           break;
       }
   }
   return fp;
}

void breakcycle(Node * head, Node* looppt)
{
   if(looppt==head)
   {
       Node* kk = head->next;
       while(kk->next!=head){
           kk= kk->next;
       }
       kk->next=NULL;
       return;
       
   }
   Node * prev = looppt;
   Node* sp = head;
   
   while(sp!=looppt){
       sp= sp->next;
       prev = looppt;
       looppt= looppt->next;
   }
   
   prev->next = NULL;
}
int main(){
   Node * head = takeInput();
   breakcycle(head,detectcycle(head));
   print(head);
   
}
