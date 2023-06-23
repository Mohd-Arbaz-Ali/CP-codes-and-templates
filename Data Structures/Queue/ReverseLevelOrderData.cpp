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

void ReverseLevelOrder(Node* root){
	if(root==NULL)
		return ;
	queue<Node*>q;
	stack<Node*>s;
	q.push(root);
	while(!q.empty()){
		root=q.front();
		s.push(q.front());
		q.pop();
		if(root->left)
			q.push(root->left);
		if(root->right)
			q.push(root->right);
	}
	while(!s.empty()){
		cout<<s.top()->data<<"\t";
		s.pop();
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	Node* root=NULL;
	insertion(&root,10);
	insertion(&root,11);
	insertion(&root,9);
	insertion(&root,70);
	insertion(&root,12);
	insertion(&root,15);
	insertion(&root,1);
	ReverseLevelOrder(root);
	return 0;
}