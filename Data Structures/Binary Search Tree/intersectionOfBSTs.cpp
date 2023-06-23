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
void helper(Node* root,map<int,int>& m){
	if(root){
		helper(root->left,m);
		m[root->data]++;
		helper(root->right,m);
	}
}
void printCommons(Node* root1,Node* root2){
	map<int, int> m;
	helper(root1,m);
	helper(root2,m);
	for(auto i=m.begin();i!=m.end();i++){
		if(i->second==2)
			cout<<i->first<<" ";
	}
	cout<<endl;
}

void printCommons2(Node* root1,Node* root2){
	stack<Node*>s1;
	stack<Node*>s2;
	while(1){
		if(root1){
			s1.push(root1);
			root1=root1->left;
		}
		else if(root2){
			s2.push(root2);
			root2=root2->left;
		}
		else if(!s1.empty() && !s2.empty()){
			if(s1.top()->data==s2.top()->data){
				root1=s1.top();
				root2=s2.top();
				cout<<root2->data<<" ";
				s1.pop();
				s2.pop();
				root1=root1->right;
				root2=root2->right;
			}
			else if(s1.top()->data<s2.top()->data){
				root1=s1.top();
				s1.pop();
				root1=root1->right;
			}
			else{
				root2=s2.top();
				s2.pop();
				root2=root2->right;
			}
		}
		else break;
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	Node* root1=NULL;
	insertion(&root1,5);
	insertion(&root1,1);
	insertion(&root1,0);
	insertion(&root1,4);
	insertion(&root1,10);
	insertion(&root1,7);
	insertion(&root1,9);

	Node* root2=NULL;
	insertion(&root2,10);
	insertion(&root2,9);
	insertion(&root2,7);
	insertion(&root2,4);
	insertion(&root2,20);

	inorder(root1);
	cout<<endl;
	inorder(root2);
	cout<<endl;

	printCommons(root1,root2);
	printCommons2(root1,root2);

	return 0;
}