#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

void atHead(Node** head_ref,int data){
	Node *new_node=new Node();
	new_node->data=data;
	new_node->next=NULL;
	if((*head_ref==NULL)){
		(*head_ref)=new_node;
		new_node->next=(*head_ref);
		return;
	}
	new_node->next=(*head_ref);
	Node *temp=(*head_ref);
	while(temp->next!=(*head_ref)){
		temp=temp->next;
	}
	temp->next=new_node;
	(*head_ref)=new_node;
}

void deleteAtHead(Node **head_ref){
	if((*head_ref)==NULL) return;

	Node *temp=(*head_ref);
	do{
		temp=temp->next;
	}while(temp->next!=(*head_ref));
	(*head_ref)=(*head_ref)->next;
	free(temp->next);
	temp->next=(*head_ref);
}

void atTail(Node **head_ref,int data){
	Node *new_node=new Node();
	new_node->data=data;
	new_node->next=NULL;

	if((*head_ref)==NULL){
		(*head_ref)=new_node;
		new_node->next=(*head_ref);
		return;
	}

	Node *temp=(*head_ref);
	while(temp->next!=(*head_ref)){
		temp=temp->next;
	}
	temp->next=new_node;
	new_node->next=(*head_ref);
}

void deletAtTail(Node **head_ref){
	if((*head_ref)==NULL)	return;

	Node *temp=(*head_ref);
	Node *prev=NULL;
	do{
		prev=temp;
		temp=temp->next;
	}while(temp->next!=(*head_ref));

	prev->next=(*head_ref);
	free(temp);
}

void printList(Node *head){
	if(head==NULL)	return;

	Node* temp=head;
	do{
		cout<<temp->data<<" ";
		temp=temp->next;
	}while(temp!=head);
	cout<<endl;
}

/*int main(int argc, char const *argv[])
{
	Node *head=NULL;
	atHead(&head,10);
	atHead(&head,20);
	atHead(&head,30);
	atHead(&head,40);
	printList(head);
	atTail(&head,50);
	atTail(&head,60);
	atTail(&head,70);
	atTail(&head,80);
	printList(head);
	deleteAtHead(&head);
	deleteAtHead(&head);
	deleteAtHead(&head);
	printList(head);
	deletAtTail(&head);
	deletAtTail(&head);
	deletAtTail(&head);
	printList(head);
	return 0;
}*/