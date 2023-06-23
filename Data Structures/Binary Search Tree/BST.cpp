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

Node* insertion(Node* root,int data){
	if(!root)
		return new Node(data);
	if(data < root->data){
		root->left=insertion(root->left,data);
	}
	else if(data>root->data)
		root->right=insertion(root->right,data);
	return root;
}

void insertion(Node** root,int data){
	if(!(*root))
		(*root)=new Node(data);
	else if(data<(*root)->data)
		insertion((*root)->left,data);
	else if(data>(*root)->data)
		insertion((*root)->right,data);
}

void inorder(Node* root){
	if(root){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

Node* minimun(Node* root){
	if(!root)
		return NULL;
	Node* current=NULL;
	while(root!=NULL){
		current=root;
		root=root->left;
	}
	return current;
}

Node *deleteNode(Node *root,  int X)
{
    if(!root)
		return NULL;
	if(root->data==X){
		if(!root->left && !root->right)
		{
			free(root);
			return NULL;
		}
		else if(root->left==NULL){
			Node* temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			Node* temp=root->left;
			free(root);
			return temp;
		}
		Node* temp=minimun(root->right);
		root->data=temp->data;
		root->right=deleteNode(root->right,temp->data);
	}
	else if(X<root->data)
		root->left=deleteNode(root->left,X);
	else
		root->right=deleteNode(root->right,X);
	return root;
}

int search(Node* root,int key){
	if(root==NULL)
		return 0;
	if(root->data==key)
		return root->data;
	else if(key<root->data)
		return (search(root->left,key));
	else
		return (search(root->right,key));
	return 0;
}

int min(Node* root){
	if(root==NULL)
		return -1;
	if(root->left==NULL)
		return root->data;
	return min(root->left);
}

int max(Node* root){
	if(root==NULL)
		return -1;
	if(root->right==NULL)
		return root->data;
	return max(root->right);
}

int main(int argc, char const *argv[])
{
	Node* root=NULL;
	root=insertion(root,10);
	root=insertion(root,20);
	root=insertion(root,5);
	root=insertion(root,1);
	insertion(&root,25);
	insertion(&root,5);
	insertion(&root,55);
	insertion(&root,50);
	insertion(&root,35);
	insertion(&root,45);
	insertion(&root,15);
	inorder(root);
	cout<<endl;
	cout<<search(root,5)<<endl;
	cout<<search(root,50)<<endl;
	cout<<min(root)<<endl;
	cout<<max(root)<<endl;
	deleteNode(root,11);
	deleteNode(root,20);
	inorder(root);
	cout<<endl;
	deleteNode(root,10);
	inorder(root);
	cout<<endl;
	deleteNode(root,1);
	inorder(root);
	cout<<endl;
	deleteNode(root,35);
	inorder(root);
	cout<<endl;
	return 0;
}