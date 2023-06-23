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

bool isIdentical(Node *r1, Node *r2)
{
	 bool res=false;
    if(!r1 && !r2)
        return true;
    if(r1==NULL || r2==NULL)
        return false;
    if(r1->data==r2->data){
        res=(isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right));
    }
    return res;
}

int main(int argc, char const *argv[])
{
	Node* root=NULL;
	insertion(&root,1);
	insertion(&root,2);
	insertion(&root,3);
	Node* root1=NULL;
	insertion(&root1,1);
	insertion(&root1,2);
	insertion(&root1,3);
	//insertion(&root1,3);
	cout<<isIdentical(root,root1)<<endl;
	//cout<<countLeavesRecursive(root)<<endl;
	return 0;
}