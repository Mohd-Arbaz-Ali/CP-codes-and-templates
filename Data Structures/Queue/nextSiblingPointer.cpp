#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;
	Node* nextSibling;

	Node(int x){
		data=x;
		left=right=nextSibling=NULL;
	}
};

void insertion(Node** root,int data){
	if(!(*root)){
		(*root)=new Node(data);
		return;
	}
	Node* temp=(*root);
	queue<Node*>q;
	q.push((*root));
	while(!q.empty()){
		temp=q.front();
		q.pop();
			if(temp->left==NULL){
				temp->left=new Node(data);
				return;
			}
			else	q.push(temp->left);

			if(temp->right==NULL){
				temp->right=new Node(data);
				return;
			}
			else	q.push(temp->right);
	}
}

void inorder(Node* root){
	if(root){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

Node* connectSiblings(Node* root) {
        if(root==NULL)
            return NULL;
        if(root->left){
            root->left->nextSibling=root->right;
        }
        if(root->right){
            root->right->nextSibling=(root->nextSibling)?root->nextSibling->left:NULL;
        }
        connectSiblings(root->left);
        connectSiblings(root->right);
        return root;
    }

int main(int argc, char const *argv[])
{
	Node* root=NULL;
	insertion(&root,1);
	insertion(&root,2);
	insertion(&root,3);
	insertion(&root,4);
	insertion(&root,5);
	insertion(&root,6);
	insertion(&root,7);
	inorder(root);
	cout<<endl;
	root=connectSiblings(root);

	return 0;
}