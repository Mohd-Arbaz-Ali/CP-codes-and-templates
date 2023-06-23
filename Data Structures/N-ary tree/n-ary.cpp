#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* firstChild;
	Node* nextSibling;

	Node(int x){
		data=x;
		firstChild=nextSibling=NULL;
	}
};

void preorder(Node* root){
	if(root){
		cout<<root->data<<" ";
		preorder(root->firstChild);
		preorder(root->nextSibling);
	}
}

void inorder(Node* root){
	if(root){
		inorder(root->firstChild);
		cout<<root->data<<" ";
		inorder(root->nextSibling);
	}
}

void postorder(Node* root){
	if(root){
		postorder(root->firstChild);
		postorder(root->nextSibling);
		cout<<root->data<<" ";
	}
}

int sum(Node *root){
	if(root==NULL)
		return 0;
	return (root->data + sum(root->firstChild) + sum(root->nextSibling));
}

int main(int argc, char const *argv[])
{
	Node* root=new Node(1);
	root->firstChild=new Node(2); 
	root->firstChild->nextSibling=new Node(3); 
	root->firstChild->nextSibling->nextSibling=new Node(4); 
	root->firstChild->nextSibling->nextSibling->nextSibling=new Node(11); 
	root->firstChild->firstChild=new Node(5); 
	root->firstChild->nextSibling->firstChild=new Node(6); 
	root->firstChild->nextSibling->firstChild->nextSibling=new Node(7); 
	root->firstChild->nextSibling->nextSibling->firstChild=new Node(8);
	root->firstChild->nextSibling->nextSibling->firstChild->nextSibling=new Node(9);
	root->firstChild->nextSibling->nextSibling->firstChild->nextSibling->nextSibling=new Node(10);
	preorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	cout<<sum(root)<<endl;
	return 0;
}