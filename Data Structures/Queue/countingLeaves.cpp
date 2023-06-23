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

int countLeaves(Node* root)
{
	if(root==NULL)
		return 0;
    queue<Node*>q;
    q.push(root);
    int count=0;
    while(!q.empty()){
        root=q.front();
        q.pop();
        if(root->left==NULL && root->right==NULL)
            count++;
        else{
            if(root->left!=NULL)
                q.push(root->left);
            if(root->right!=NULL)
                q.push(root->right);
        }
    }
    return count;
}

int countLeavesRecursive(Node* root){
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right== NULL)
		return 1;
	else return countLeavesRecursive(root->left)+countLeavesRecursive(root->right);
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
	cout<<countLeaves(root)<<endl;
	cout<<countLeavesRecursive(root)<<endl;
	return 0;
}