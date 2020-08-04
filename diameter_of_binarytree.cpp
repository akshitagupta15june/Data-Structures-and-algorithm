#include <iostream>
#include<algorithm>
//8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
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
int height(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    int ls=height(root->left);
    int rs=height(root->right);
    return max(ls,rs)+1;
    
}
void printkthlevel(node*root,int k)
{
    if(root==NULL)
    {
      return;  
    }
    if(k==1)
    {
        cout<<root->data<<" ";
        return;
    }
    printkthlevel(root->left,k-1);
    printkthlevel(root->right,k-1);
    return;
}
void printalllevel(node*root)
{
    int h=height(root);
    for(int i=1;i<=h;i++)
    {
        printkthlevel(root,i);
        cout<<endl;
    }
    return;
}
void bfs(node*root)
{
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node* f=q.front();
        cout<<f->data<<" ";
        q.pop();
        if(f->left)
        {
            q.push(f->left);
        }
        if(f->right)
        {
            q.push(f->right);
        }
    }
    return;
}
int count(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    return (root->data)+count(root->left)+count(root->right);
}
class Pair{
public:
    int height;
    int diameter;
};
Pair fastdiameter(node*root)
{
    Pair p;
    if(root==NULL)
    {
        p.diameter=p.height=0;
        return p;
    }
    Pair left=fastdiameter(root->left);
    Pair right=fastdiameter(root->right);
    p.height=max(left.height,right.height)+1;
    p.diameter=max(left.height+right.height,max(left.diameter,right.diameter));
    return p;
}
int main(int argc, char **argv)
{
	node*root=buildtree();
    //preorderprint(root);
    //cout<<endl;
    //postorderprint(root);
    //cout<<endl;
    //inorderprint(root);
    cout<<endl;
   // cout<<height(root);
   // printalllevel(root);
   //bfs(root);
   //cout<<count(root)<<endl;
   Pair p=fastdiameter(root);
   cout<<p.height<<endl;
   cout<<p.diameter<<endl;
	return 0;
}
