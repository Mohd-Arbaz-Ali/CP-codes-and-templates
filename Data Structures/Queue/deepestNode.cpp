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

void findDeepest(Node* root,int level,int &maxlvl,int &res){
	if(root){
		findDeepest(root->left,level+1,maxlvl,res);
		findDeepest(root->right,level+1,maxlvl,res);
		if(level>=maxlvl){
			maxlvl=level;
			res=root->data;
		}
	}
}

int deepestNodeRecursive(Node* root){
	if(!root)
		return -1;
	int level=0,maxlvl=-1,res;
	findDeepest(root,level,maxlvl,res);
	return res;
}

int main(int argc, char const *argv[])
{
	Node* root = createNode(1); 
    root->left = createNode(2); 
    root->right = createNode(3); 
    root->left->left = createNode(4); 
    root->right->left = createNode(5); 
    root->right->right = createNode(6); 
    root->right->left->right = createNode(7); 
    root->right->right->right = createNode(8); 
    root->right->left->right->right = createNode(9); 
    cout << deepestNode(root)<<endl; 
	cout<<deepestNodeRecursive(root)<<endl;
	return 0;
}