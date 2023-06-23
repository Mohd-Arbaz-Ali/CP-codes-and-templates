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

void preorder(Node* root){
	if(root){
		cout<<root->data<<"\t";
		preorder(root->left);
		preorder(root->right);
	}
}

int maxElement(Node* root){
	int maxNum=INT_MIN,root_val,left,right;
	if(root){
		root_val=root->data;
		left=maxElement(root->left);
		right=maxElement(root->right);

		maxNum=max(left,right);
		maxNum=max(maxNum,root_val);
	}
	return maxNum;
}

int minElement(Node* root){
	int minnum=INT_MAX,root_val,left,right;
    if(root){
        root_val=root->data;
        left=minElement(root->left);
        right=minElement(root->right);
        
        minnum=min(left,right);
        minnum=min(minnum,root_val);
    }
    return minnum;
}

int main(int argc, char const *argv[])
{
	Node* root=NULL;
	insertion(&root,10);
	insertion(&root,11);
	insertion(&root,9);
	insertion(&root,7);
	insertion(&root,12);
	insertion(&root,15);
	insertion(&root,1);
	preorder(root);
	cout<<endl;
	cout<<maxElement(root)<<endl;
	cout<<minElement(root)<<endl;
	return 0;
}