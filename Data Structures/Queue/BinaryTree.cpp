#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;
};

Node* createNode(int data){

	Node* new_node=new Node();
	new_node->data=data;
	new_node->left=new_node->right=NULL;

	return new_node;
}

Node* insertion(Node* root,int data){
	if(root==NULL){
		root=createNode(data);
		return root;
	}

	Node* new_node=createNode(data);
	Node* temp=root;
	queue<Node*>q;
	q.push(root);

	while(!q.empty()){

		root=q.front();
		q.pop();
		if(root->left==NULL){
			root->left=new_node;
			return temp;
		}
		else
			q.push(root->left);

		if(root->right==NULL){
			root->right=new_node;
			return temp;
		}
		else
			q.push(root->right);
	}

	return temp;
}

void preorder(Node* root){
	if(root==NULL)
		return;
	cout<<root->data<<'\t';
	preorder(root->left);
	preorder(root->right);
}

void inorder(Node* root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<"\t";
	inorder(root->right);
}

void postorder(Node* root){
	if(root){
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<"\t";
	}
}

bool SearchingRecursive(Node* root,int data){
	bool res=false;
	if(root){
		if(root->data==data){
			return true;
		}
		else{
			res=SearchingRecursive(root->left,data);
			if(res==false)
				res=SearchingRecursive(root->right,data);	
		}
	}
	return res;
}
int deepestNode(Node* root){
	if(!root)
		return 0;
	queue<Node*>q;
	q.push(root);
	int temp;
	while(!q.empty()){
		root=q.front();
		temp=root->data;
		q.pop();
		if(root->left!=NULL)
			q.push(root->left);
		if(root->right!=NULL)
			q.push(root->right);
	}
	return temp;
}

void deleteNode(Node* root){
	
}

void levelOrder(Node* root){
	if(root==NULL)
		return ;
	queue<Node*>q;
	q.push(root);
	while(!q.empty()){
		root=q.front();
		q.pop();
		cout<<root->data<<"\t";
		if(root->left)
			q.push(root->left);
		if(root->right)
			q.push(root->right);
	}
}

int sizeOfBinaryTree(Node* root){
	if(root==NULL)
		return 0;
	return sizeOfBinaryTree(root->left)+1+sizeOfBinaryTree(root->right); 
}

int main(int argc, char const *argv[])
{
	Node* root=createNode(1);
	root->left=createNode(2);
	root->right=createNode(3);
	root->left->left=createNode(4);
	root->right->left=createNode(5);
	preorder(root);
	cout<<endl;
	root=insertion(root,6);
	preorder(root);
	cout<<endl;
	Node* root1=NULL;
	root1=insertion(root1,1);
	root1=insertion(root1,2);
	root1=insertion(root1,3);
	root1=insertion(root1,4);
	root1=insertion(root1,5);
	root1=insertion(root1,6);
	preorder(root1);
	cout<<endl;
	inorder(root1);
	cout<<endl;
	postorder(root1);
	cout<<endl;
	levelOrder(root1);
	cout<<endl;
	cout<<sizeOfBinaryTree(root1)<<endl;
	return 0;
}