#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data=x;
        left=right=NULL;
    }
};

void insertion(Node** root,int data){
	if((*root)==NULL){
		(*root)=new Node(data);
		return;
	}
	queue<Node*>q;
	q.push((*root));
	Node* temp;
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

vector <int> zigZagTraversal(Node* root)
{
	vector<int > v;
	queue<Node*>q;
	stack<int>s;
	q.push(root);
	q.push(NULL);
	int i=1;
	while(!q.empty()){
	    root=q.front();
	    q.pop();
	    if(root){
	        if(root->left)
	            q.push(root->left);
	        if(root->right)
	            q.push(root->right);
	    }
	    else{
	        if(!q.empty()){
	            q.push(NULL);
	            i++;
	        }
	    }
	    
	    if(root && i%2==0){
	        s.push(root->data);
	    }
	    else if(root){
	        while(!s.empty()){
	            v.push_back(s.top());
	            s.pop();
	        }
	        v.push_back(root->data);
	    }
	}
	while(!s.empty()){
		v.push_back(s.top());
		s.pop();
	}
	return v;
}
void levelOrder(Node* root){
	if(root==NULL)
		return ;
	queue<Node*>q;
	q.push(root);
	while(!q.empty()){
		root=q.front();
		q.pop();
		cout<<root->data<<"\t";
		if(root->left)
			q.push(root->left);
		if(root->right)
			q.push(root->right);
	}
}

int main(int argc, char const *argv[])
{
	/*Node *root=NULL;
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
	insertion(&root,1);*/
	Node* root=new Node(3);
	root->left=new Node(9);
	root->right=new Node(20);
	root->right->right=new Node(7);
	root->right->left=new Node(15);
	levelOrder(root);
	cout<<endl;
	vector<int>v;
	v=zigZagTraversal(root);
	for(auto i=v.begin();i!=v.end();i++){
		cout<<*i<<" ";
	}
	cout<<endl;
	return 0;
}