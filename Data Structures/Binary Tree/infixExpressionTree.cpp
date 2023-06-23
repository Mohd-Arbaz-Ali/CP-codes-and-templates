#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	char data;
	Node* left;
	Node* right;

	Node(char c){
		data=c;
        left=right=NULL;
	}
};
int precedence(char it){
	if(it=='^')
		return 3;
	else if(it=='*' || it=='/')
		return 2;
	else if(it=='+' || it=='-')
		return 1;
	return 0;
}
Node* buildTree(string infix){
    infix="("+infix;
    infix+=")";
	stack<char>ch;
	stack<Node*>n;
	for(auto it : infix){
	    if(it=='(')
			ch.push(it);
	    else if(isalpha(it)){
        	n.push(new Node(it));
        }
        else if(it==')'){
            while(ch.top()!='('){
                Node* op=new Node(ch.top());
                ch.pop();
                op->right=n.top();
                n.pop();
                op->left=n.top();
                n.pop();
                n.push(op);
            }
            ch.pop();
        }
        else{
            while((precedence(ch.top())>=precedence(it) && it!='^')){
                Node* op=new Node(ch.top());
                ch.pop();
                op->right=n.top();
                n.pop();
                op->left=n.top();
                n.pop();
                n.push(op);
            }
            ch.push(it);
        }
	}
	return n.top();
}

void inorder(Node* expTree){
	if(expTree){
		inorder(expTree->left);
		cout<<expTree->data;
		inorder(expTree->right);
	}
}
void preorder(Node* expTree){
	if(expTree){
		cout<<expTree->data;
		preorder(expTree->left);
		preorder(expTree->right);
	}
}
void postorder(Node* expTree){
	if(expTree){
		postorder(expTree->left);
		postorder(expTree->right);
		cout<<expTree->data;
	}
}

int main(int argc, char const *argv[])
{
	string infix;
	cin>>infix;
	Node* expTree=buildTree(infix);
	inorder(expTree);
	cout<<endl;
	preorder(expTree);
	cout<<endl;
	postorder(expTree);
	cout<<endl;
	return 0;
}