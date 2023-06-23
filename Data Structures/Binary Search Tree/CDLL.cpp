#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;

	Node(int x){
		data=x;
		left=right=NULL;
	}
};

Node* insertion(Node* root,int data){
	if(!root)
		return new Node(data);
	if(data < root->data){
		root->left=insertion(root->left,data);
	}
	else if(data>root->data)
		root->right=insertion(root->right,data);
	return root;
}

void inorder(Node* root){
	if(root){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

Node* minimun(Node* root){
	if(!root)
		return NULL;
	Node* current=NULL;
	while(root!=NULL){
		current=root;
		root=root->left;
	}
	return current;
}

void helper(Node* root,Node** head){
	if(root){
		helper(root->left,head);
		if(*head){
			(*head)->right=root;
			root->left=(*head);
			(*head)=(*head)->right;
		}
		else
			(*head)=root;
		helper(root->right,(head));
	}
}

Node* BSTtoCDLL(Node* root){
	if(!root)
		return NULL;
	Node* head=minimun(root);
	Node* temp=NULL;
	helper(root,&temp);
	temp=head;
	while(temp->right)
		temp=temp->right;
	head->left=temp;
	temp->right=head;
	return head;
}

void printLL(Node* head){
	if(!head)
		return ;
	Node* temp=head;
	cout<<"Printing in forward direction : ";
	do{
		cout<<temp->data<<" ";
		temp=temp->right;
	}while(temp!=head);
	cout<<endl;
	cout<<"Printing in backward direction : ";
	do{
		temp=temp->left;
		cout<<temp->data<<" ";
	}while((temp!=head));
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	Node* root=NULL;
	root=insertion(root,10);
	root=insertion(root,7);
	root=insertion(root,15);
	root=insertion(root,12);
	root=insertion(root,16);
	root=insertion(root,9);
	root=insertion(root,8);
	root=insertion(root,6);
	root=insertion(root,5);
	root=insertion(root,4);

	inorder(root);
	cout<<endl;

	Node* head=BSTtoCDLL(root);
	printLL(head);

	return 0;
}