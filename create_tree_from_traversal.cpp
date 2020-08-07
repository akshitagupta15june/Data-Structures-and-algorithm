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


int replacesum(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return root->data;
    }
    int leftsum=replacesum(root->left);
    int rightsum=replacesum(root->right);
    int temp=root->data;
    root->data=leftsum+rightsum;
    return temp+root->data;
}
node* buildtreefromarray(int *a,int s,int e)
{
    if(s>e)
    {
        return NULL;
    }
    int mid=(s+e)/2;
    node*root=new node(a[mid]);
    root->left=buildtreefromarray(a,s,mid-1);
    root->right=buildtreefromarray(a,mid+1,e);
    return root;
}
node* createTreeFromTrav(int *in,int *pre,int s,int e){
    static int i = 0;
    //Base Case
    if(s>e){
        return NULL;
    }
    //Rec Case
    node *root = new node(pre[i]);

    int index=-1;
    for(int j=s;s<=e;j++){
        if(in[j]==pre[i]){
            index = j;
            break;
        }
    }

    i++;
    root->left = createTreeFromTrav(in,pre,s,index-1);
    root->right = createTreeFromTrav(in,pre,index+1,e);
    return root;
}
int main(int argc, char **argv)
{
	//node*root=buildtree();
    //replacesum(root);
    //bfs(root);
    //preorderprint(root);
    //cout<<endl;
    //postorderprint(root);
    //cout<<endl;
    //inorderprint(root);
   // cout<<endl;
   // cout<<height(root);
   // printalllevel(root);
   //bfs(root);
   //int a[]={1,2,3,4,5,6,7};
   //int n=7;
   //node*root=buildtreefromarray(a,0,n-1);
   int in[]={3,2,8,4,1,6,7,5};
   int pre[]={1,2,3,4,8,5,6,7};
   int n=sizeof(in)/sizeof(int);
   node*root=createTreeFromTrav(in,pre,0,n-1);
   bfs(root);
	return 0;
}
