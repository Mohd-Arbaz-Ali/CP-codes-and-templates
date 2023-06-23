#include<bits/stdc++.h>
using namespace std;

class Node{

	public:
		int data;
		Node* prev;
		Node* next;

		Node(int x){
			data=x;
			prev=next=NULL;
		}
};

void push(Node **head_ref,int data){
	Node *node=new Node(data);
	Node *temp=(*head_ref);
	if((*head_ref)==NULL){
		(*head_ref)=node;
		return;
	}
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=node;
	node->prev=temp;
}

void printList(Node *head){
	Node *tail=NULL;
	if(head==NULL)
		return;
	printf("Forward traveral : ");
	while(head!=NULL){
		cout<<head->data<<" ";
		tail=head;
		head=head->next;
	}
	cout<<endl;
	printf("Reverse traversal : ");
	while(tail!=NULL){
		cout<<tail->data<<" ";
		tail=tail->prev;
	}
	cout<<endl;
}

Node* mid(Node* head){
	if(!head)
		return NULL;
	Node* temp=head;
	while(temp && temp->next){
		head=head->next;
		temp=temp->next->next;
	}
	return head;
}

Node* DLL2BalBST(Node* head){
	if(!head || !head->next)
		return head;
	Node* root=mid(head);
	Node* temp=NULL;
	if(root->next){
		temp=root->next;
		temp->prev=NULL;
	}
	root->next=NULL;
	root->prev->next=NULL;
	root->prev=NULL;
	root->prev=DLL2BalBST(head);
	root->next=DLL2BalBST(temp);
	return root;
}

void inorder(Node* root){
	if(root){
		inorder(root->prev);
		cout<<root->data<<" ";
		inorder(root->next);
	}
}

int main(int argc, char const *argv[])
{
	Node *head=NULL;
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	push(&head,6);
	push(&head,7);
	push(&head,8);
	printList(head);

	Node* root=DLL2BalBST(head);
	inorder(root);
	cout<<endl;

	return 0;
}