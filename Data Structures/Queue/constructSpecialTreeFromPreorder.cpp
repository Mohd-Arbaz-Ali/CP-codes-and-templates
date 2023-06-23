#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	char data;
	Node* left;
	Node* right;

	Node(char ch){
		data=ch;
		left=right=NULL;
	}
};

Node* construct(string pre,int &i,int n){
	if(n==i)
		return NULL;

	Node* new_node=new Node(pre[i++]);

	if(new_node->data=='I'){

		new_node->left=construct(pre,i,n);
		new_node->right=construct(pre,i,n);

	}

	return new_node;
}

Node* constructBT(string pre){
	int i=0;
	return construct(pre,i,pre.size());
}

void preorder(Node* root){
	if(root){
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

int main(int argc, char const *argv[])
{
	string pre="ILILL";
	Node* root=constructBT(pre);
	preorder(root);
	cout<<endl;
	string pre1="IILLL";
	Node* root1=constructBT(pre1);
	preorder(root1);
	cout<<endl;
	return 0;
}