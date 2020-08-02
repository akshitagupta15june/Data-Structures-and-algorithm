#include <iostream>
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
node*buildtree()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    node*root=new node(d);
    root->left=buildtree();
    root->right=buildtree();
    return root;
}
void preorderprint(node*root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorderprint(root->left);
    preorderprint(root->right);
}
void postorderprint(node*root)
{
    if(root==NULL)
    {
        return;
    }
    postorderprint(root->left);
    postorderprint(root->right);
    cout<<root->data<<" ";
}
void inorderprint(node*root)
{
    if(root==NULL)
    {
        return;
    }
    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);
}
int main(int argc, char **argv)
{
	node*root=buildtree();
    preorderprint(root);
    cout<<endl;
    postorderprint(root);
    cout<<endl;
    inorderprint(root);
    cout<<endl;
    
	return 0;
}
