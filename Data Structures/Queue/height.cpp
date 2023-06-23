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

void insertion(Node** root,int data){
	if((*root)==NULL){
		(*root)=createNode(data);
		return;
	}
	queue<Node*>q;
	q.push((*root));
	Node* temp;
	while(!q.empty()){
		temp=q.front();
		q.pop();

		if(temp->left==NULL){
			temp->left=createNode(data);
			return;
		}
		else	q.push(temp->left);

		if(temp->right==NULL){
			temp->right=createNode(data);
			return;
		}
		else	q.push(temp->right);
	}
}

int height(Node* root){
	int count=0,left,right;
	if(root){
		left=height(root->left);
		right=height(root->right);
		count=max(left,right) + 1;
	}
	return count;
}

int heightIterative(Node* root){
	if(!root)
		return 0;
	queue<Node*>q;
	q.push(root);
	q.push(NULL);
	int count=0;
	while(!q.empty()){
		root=q.front();
		q.pop();
		if(root){
			if(root->left!=NULL){
				q.push(root->left);
			}
			if(root->right!=NULL)
				q.push(root->right);
		}
		else{
			count++;
			if(!q.empty())
				q.push(NULL);
		}
	}
	return count;
}

int main(int argc, char const *argv[])
{
	Node* root=NULL;
	insertion(&root,10);
	root->left=createNode(2);
	root->left->left=createNode(3);
	root->left->left->left=createNode(4);
	insertion(&root,11);
	insertion(&root,9);
	insertion(&root,70);
	insertion(&root,12);
	insertion(&root,15);
	insertion(&root,1);
	insertion(&root,1);
	root->right->right->right=createNode(5);
	cout<<height(root)<<endl;
	cout<<heightIterative(root)<<endl;
	return 0;
}