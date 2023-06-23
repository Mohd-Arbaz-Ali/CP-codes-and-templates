#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;

	Node(int x){
		data=x;
		left=right=NULL;
	}
};

void insertion(Node** root,int val){

	if(*root==NULL){
		(*root)=new Node(val);
		return;
	}

	if(val<(*root)->data)
		insertion(&(*root)->left,val);

	else if(val>(*root)->data)
		insertion(&(*root)->right,val);
}

void inorder(Node* root){
	if(root){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

void helper(Node* root1,Node* root2){
	if(root2){
		insertion(&root1,root2->data);
		helper(root1,root2->left);
		helper(root1,root2->right);
	}
}

Node* merge(Node* root1,Node* root2){
	if(!root1 &&!root2)
		return NULL;
	if(!root1 || !root2){
		return (!root1)? root2 : root1;
	}
	if(root2->data<root1->data)
		swap(root1,root2);
	helper(root1,root2);
	return root1;
}

int main(int argc, char const *argv[])
{
	Node* root1=NULL;
	insertion(&root1,5);
	insertion(&root1,1);
	insertion(&root1,0);
	insertion(&root1,4);
	insertion(&root1,10);
	insertion(&root1,7);
	insertion(&root1,9);

	Node* root2=NULL;
	insertion(&root2,10);
	insertion(&root2,9);
	insertion(&root2,7);
	insertion(&root2,4);
	insertion(&root2,20);

	inorder(root1);
	cout<<endl;
	inorder(root2);
	cout<<endl;

	root1=merge(root1,root2);
	inorder(root1);
	cout<<endl;

	return 0;
}