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
	if(head_ref->next==NULL)
		return head_ref;

	Node* X=head_ref;
	Node* Y=NULL;
	while(X!=NULL){
		Y=new Node();
		Y->data=X->data;
		Y->next=X->next;
		X->next=Y;
		Y->rand=NULL;
		X=X->next->next;
	}
	X=head_ref;
	Y=head_ref->next;
	while(Y->next!=NULL){
		Y->rand=X->rand->next;
		X=X->next->next;
		Y=Y->next->next;
	}
	Y->rand=X->rand->next;

	X=head_ref;
	Y=head_ref->next;
	while(Y->next!=NULL){
		X->next=Y->next;
		Y->next=Y->next->next;
		X=X->next;
		Y=Y->next;
	}
	return head_ref;
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

	Node* cl=clone(head);
	printList(cl);
	printList(head);

	return 0;
}