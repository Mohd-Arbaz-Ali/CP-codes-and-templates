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

int CountingFullNodes(Node* root){
	if(root==NULL)
		return 0;
	int count=0;
	if(root->left && root->right)
		count++;
	count+=CountingFullNodes(root->left)+CountingFullNodes(root->right);
	return count;
}

int main(int argc, char const *argv[])
{
	Node* root=NULL;
	insertion(&root,1);
	insertion(&root,2);
	insertion(&root,3);
	insertion(&root,4);
	insertion(&root,4);
	insertion(&root,4);
	insertion(&root,5);
	insertion(&root,6);
	insertion(&root,7);
	cout<<CountingFullNodes(root)<<endl;
	//cout<<countLeavesRecursive(root)<<endl;
	return 0;
}