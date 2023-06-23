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

int Mirror(Node* root1,Node* root2){
	if(!root2 && !root1)
		return 1;
	if(!root2 || !root1)
		return 0;
	if(root1->data!=root2->data)
		return 0;
	return (Mirror(root1->left,root2->right) && Mirror(root1->right,root2->left));
}

int main(int argc, char const *argv[])
{
	Node* root1=createNode(1);
	root1->left=createNode(2);
	root1->right=createNode(3);
	root1->left->right=createNode(5);
	root1->left->left=createNode(4);
	Node* root2=createNode(1);
	root2->right=createNode(2);
	root2->left=createNode(3);
	root2->right->left=createNode(5);
	root2->right->right=createNode(4);
	cout<<Mirror(root1,root2)<<endl;
	return 0;
}