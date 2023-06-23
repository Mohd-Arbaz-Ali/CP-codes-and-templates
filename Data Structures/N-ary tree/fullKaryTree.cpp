#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	vector<Node*> child;

	Node(int x){
		data=x;
	}
};

Node* BuildKaryTree(vector<int>& pre,int h,int k,int& idx){
	if(idx<pre.size() && h){
		Node* new_node=new Node(pre[idx++]);
		for(int i=0;i<k;i++)
			new_node->child.push_back(BuildKaryTree(pre,h-1,k,idx));
		return new_node;
	}
	return NULL;
}

Node* BuildKaryTree(vector<int>& pre,int k,int n){
	if(n==0)
		return NULL;
	int idx=0;
	int height=ceil(log((double)n*2+1)/log(k));
	//cout<<height;
	return BuildKaryTree(pre,height,k,idx);
}

void postorder(Node* root){
	if(root){
		for(int i=0;i<root->child.size();i++){
			postorder(root->child[i]);
		}
		cout<<root->data<<" ";
	}
}

int main(int argc, char const *argv[])
{
	vector<int> pre{1,2,5,6,7,3,8,9,10,4};
	int k=3;
	Node* root=BuildKaryTree(pre,k,pre.size());
	postorder(root);
	cout<<endl;
	return 0;
}