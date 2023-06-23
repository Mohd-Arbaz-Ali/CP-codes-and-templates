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

int dia(Node* root,int &max_num){
    if(root==NULL)
        return 0;
    int left,right;
    left=dia(root->left,max_num);
    right=dia(root->right,max_num);
    max_num=max(max_num,left+right+1);
    if(left>right)
        return left+1;
    return right+1;
}
int diameter(Node* root) {
    int max_num=INT_MIN;
    dia(root,max_num);
    return max_num;
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
	insertion(&root,8);
	insertion(&root,9);
	insertion(&root,0);
	insertion(&root,1);
	insertion(&root,1);
	cout<<diameter(root)<<endl;
	return 0;
}