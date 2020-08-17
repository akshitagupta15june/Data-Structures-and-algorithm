#include <iostream>
#include<queue>
using namespace std;

class node{
    
public:
    int data;
    node*left;
    node*right;
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};
node* insertInBST(node*root,int data)
{
    if(root==NULL)
    {
        return new node(data);
    }
    if(data<=root->data){
        root->left=insertInBST(root->left,data);
    }
    else{
        root->right=insertInBST(root->right,data);
    }
    return root;
}
bool search(node*root,int data)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==data)
    {
        return true;
    }
    if(data<=root->data)
    {
        return search(root->left,data);
    }
    else{
        return search(root->right,data);
    }
    
}
node*build(){
    int d;
    cin>>d;
    node*root=NULL;
    while(d!=-1)
    {
        root=insertInBST(root,d);
        cin>>d;
    }
    return root;
    
}
void bfs(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<",";
            q.pop();

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
}
//Inorder Print
void preorder(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    
    preorder(root->right);
}

int main(){ 
    node*root = build();
    preorder(root);
    cout<<endl;
    //bfs(root);
    int s;
    cin>>s;
    if(search(root,s))
    {
        cout<<"Present";
    }
    else
    {
        cout<<"not present";
    }

return 0;
}
