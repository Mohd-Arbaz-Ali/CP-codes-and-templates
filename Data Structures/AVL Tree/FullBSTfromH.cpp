#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;

};

Node* constructBST(int h,int &count){
	if(h==0)
		return NULL;
	Node* temp=new Node();
	temp->left=constructBST(h-1,count);
	temp->data=count++;
	temp->right=constructBST(h-1,count);
	return temp;
}

/*Node* constructBST2(int l,int r)
{
	if(l>r)
		return NULL;
	int mid=l+((r-l)/2);
	Node* temp=new Node();
	temp->data=mid;
	temp->left=constructBST2(l,mid-1);
	temp->right=constructBST2(mid+1,r);
	return temp;
}*/

void inorder(Node* root){
	if(root){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

int main(int argc, char const *argv[])
{
	Node* root=NULL;
	int count=1;
	root=constructBST(3,count);
	inorder(root);
	cout<<endl;

	/*Node* node=NULL;
	int h=3;
	node=constructBST2(1,1<<h);
	inorder(node);
	cout<<endl;*/
	return 0;
}