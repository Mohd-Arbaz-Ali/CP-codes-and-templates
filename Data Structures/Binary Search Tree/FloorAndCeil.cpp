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

void insertion(Node** root,int val){

	if(*root==NULL){
		(*root)=new Node(val);
		return;
	}

	if(val<(*root)->data)
		insertion(&(*root)->left,val);

	else if(val>(*root)->data)
		insertion(&(*root)->right,val);
}

void inorder(Node* root){
	if(root){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

void FloorAndCeil(Node* root,int k,int &floor,int &ceil){
	if(!root)
		return;
	if(k==root->data){
		floor=ceil=root->data;
		return;
	}
	if(k<root->data){
		ceil=root->data;
		FloorAndCeil(root->left,k,floor,ceil);
	}
	if(k>root->data){
		floor=root->data;
		FloorAndCeil(root->right,k,floor,ceil);
	}
}

void FloorAndCeil(Node* root,int k){
	if(!root)
		return ;
	int floor=-1,ceil=-1;
	FloorAndCeil(root,k,floor,ceil);
	cout<<"Floor = "<<floor<<"   ";
	cout<<"Ceil = "<<ceil<<endl;
}

void floorUtil(Node* root,int k,int &floor){
	if(!root)
		return ;
	if(root->data==k){
		floor=root->data;
		return;
	}
	if(k<root->data)
		floorUtil(root->left,k,floor);
	if(k>root->data){
		floor=root->data;
		floorUtil(root->right,k,floor);
	}
}
int findFloor(Node* root,int k){
	if(!root)
		return -1;
	int floor=-1;
	floorUtil(root,k,floor);
	return floor;
}

void ceilUtil(Node* root,int k,int &ceil){
	if(!root)
		return ;
	if(root->data==k){
		ceil=root->data;
		return;
	}
	if(k<root->data){
		ceil=root->data;
		ceilUtil(root->left,k,ceil);
	}
	if(k>root->data)
		ceilUtil(root->right,k,ceil);
}
int findCeil(Node* root,int k){
	if(!root)
		return -1;
	int ceil=-1;
	ceilUtil(root,k,ceil);
	return ceil;
}

int main(){
	Node* root=NULL;
	insertion(&root,8);
	insertion(&root,4);
	insertion(&root,12);
	insertion(&root,2);
	insertion(&root,6);
	insertion(&root,10);
	insertion(&root,14);

	inorder(root);
	cout<<endl;

	FloorAndCeil(root,5);
	FloorAndCeil(root,6);
	FloorAndCeil(root,1);
	FloorAndCeil(root,11);
	FloorAndCeil(root,15);

	cout<<findFloor(root,5)<<endl;
	cout<<findFloor(root,6)<<endl;
	cout<<findFloor(root,1)<<endl;
	cout<<findFloor(root,11)<<endl;
	cout<<findFloor(root,15)<<endl;

	cout<<findCeil(root,5)<<endl;
	cout<<findCeil(root,6)<<endl;
	cout<<findCeil(root,1)<<endl;
	cout<<findCeil(root,11)<<endl;
	cout<<findCeil(root,15)<<endl;

	return 0;
}