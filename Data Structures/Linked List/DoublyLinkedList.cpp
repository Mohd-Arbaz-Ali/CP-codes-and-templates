#include<bits/stdc++.h>
using namespace std;

class DoublyLL{

	public:
		int data;
		DoublyLL* prev;
		DoublyLL* next;

};

DoublyLL *creatNode(int data){
	DoublyLL *node=new DoublyLL();
	node->data=data;
	node->next=NULL;
	node->prev=NULL;
	return node;
}

void atHead(DoublyLL** head,int data){
	DoublyLL *node=creatNode(data);
	node->next=*head;
	if((*head)!=NULL)
		(*head)->prev=node;
	*head=node;
}
void deleteAtHead(DoublyLL **head_ref){
	if((*head_ref)==NULL)
		return;
	(*head_ref)=(*head_ref)->next;
	free((*head_ref)->prev);
	(*head_ref)->prev=NULL;
}

void atTail(DoublyLL **head_ref,int data){
	DoublyLL *node=creatNode(data);
	DoublyLL *temp=(*head_ref);
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
void deleteAtTail(DoublyLL *head){
	if(head==NULL)
		return;

	while(head->next!=NULL)	head=head->next;

	head->prev->next=NULL;
	free(head);
}
void insertBefore(DoublyLL **head_ref,int node,int data){
	
	DoublyLL *new_node=creatNode(data);
	DoublyLL *temp=(*head_ref);

	while((temp!=NULL)&&(temp->data!=node)) temp=temp->next;
	if(temp==NULL){
		cout<<"Node doesnt exist\n";	return;
	}
	new_node->prev=temp->prev;
	new_node->next=temp;
	temp->prev=new_node;
}

void printList(DoublyLL *head){
	DoublyLL *tail=NULL;
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

int main(int argc, char const *argv[])
{
	DoublyLL *head=NULL;
	atHead(&head,10);
	atTail(&head,20);
	insertBefore(&head,20,30);
	insertBefore(&head,40,30);
	printList(head);

	return 0;
}