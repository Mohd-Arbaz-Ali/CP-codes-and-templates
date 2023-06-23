#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* firstChild;
	Node* nextSibling;

	Node(int x){
		data=x;
		firstChild=nextSibling=NULL;
	}
};

void inorder(Node* root){
	if(root){
		inorder(root->firstChild);
		cout<<root->data<<" ";
		inorder(root->nextSibling);
	}
}

int heightOrDepth(vector<int>& p){
	int maxD=INT_MIN;
	int currD=INT_MIN,j;
	for(int i=0;i<p.size();i++){
		currD=0;
		j=i;
		while(p[j]!=-1){
			currD++;
			j=p[j];
		}
		maxD=max(currD,maxD);
	}
	return maxD;
}

int main(int argc, char const *argv[])
{
	Node* root=new Node(0);
	root->firstChild=new Node(5);
	root->firstChild->nextSibling=new Node(1);
	root->firstChild->nextSibling->nextSibling=new Node(6);
	root->firstChild->nextSibling->firstChild=new Node(2);
	root->firstChild->nextSibling->firstChild->firstChild=new Node(7);
	root->firstChild->nextSibling->firstChild->firstChild->firstChild=new Node(8);
	root->firstChild->nextSibling->nextSibling->firstChild=new Node(4);
	root->firstChild->nextSibling->nextSibling->firstChild->nextSibling=new Node(3);
	inorder(root);
	cout<<endl;
	vector<int> p(9);
	p[0]=-1;
	p[1]=0;
	p[2]=1;
	p[3]=6;
	p[4]=6;
	p[5]=0;
	p[6]=0;
	p[7]=2;
	p[8]=7;

	cout<<heightOrDepth(p)<<endl;

	return 0;
}