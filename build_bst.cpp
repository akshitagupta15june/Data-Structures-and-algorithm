#include<bits/stdc++.h>
using namespace std;
class node{
	public:
	int data;
	node*right=NULL;
	node*left=NULL;
	node(int d)
    {
		data=d;
		right=NULL;
		left=NULL;
	}
};
//node *root;
node*buildbst(int *b,int start,int end)
{
    
    if(start>end)
    {
        return NULL;
    }
	//while(start<end){
		int mid=(start+end)/2;
		node *r=new node(b[mid]);
		r->left=buildbst(b,start,mid-1);
		r->right=buildbst(b,mid+1,end);
	//}
	return r;
}
void preorder(node*root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[100000];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		
    node*root=buildbst(a,0,n-1);
	preorder(root);
	cout<<endl;
	}
	return 0;
}
