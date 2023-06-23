#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		Node *rand;
};

void push(Node** head_ref,int data){
	Node* new_node=new Node();
	new_node->data=data;
	new_node->next=NULL;
	new_node->rand=NULL;

	if((*head_ref)==NULL){
		(*head_ref)=new_node;
		return;
	}
	new_node->next=(*head_ref);
	(*head_ref)=new_node;
}

Node* clone(Node* head_ref){
	if(head_ref==NULL)
		return NULL;
	unordered_map<Node*,Node*>um;
	Node* X=head_ref;
	Node* Y=NULL;
	while(X!=NULL){
		Y=new Node();
		Y->data=(X->data)+1;
		Y->next=NULL;
		Y->rand=NULL;
		um[X]=Y;
		X=X->next;
	}
	Node *temp=head_ref;
	while(head_ref!=NULL){
		um[head_ref]->next=um[head_ref->next];
		um[head_ref]->rand=um[head_ref->rand];
		head_ref=head_ref->next;
	}
	return um[temp];
}

void printList(Node* head_ref){
	while(head_ref!=NULL){
		cout<<head_ref->data<<"|"<<head_ref->rand->data<<"  ";
		head_ref=head_ref->next;
	}
	cout<<endl;
}

int main(){
	Node* head=NULL;
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	//printList(head);

	head->rand=head->next->next;
	head->next->rand=head->next->next->next->next;
	head->next->next->rand=head->next;
	head->next->next->next->rand=head;
	head->next->next->next->next->rand=head->next;
	printList(head);

	Node* cl=clone(head);
	printList(cl);

	return 0;
}