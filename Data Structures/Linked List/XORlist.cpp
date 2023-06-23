#include<bits/stdc++.h>
#include<cinttypes>
using namespace std;

class Node{
public:
	int data;
	Node* npx;
};

Node* XOR(Node* a,Node* b){
	return reinterpret_cast<Node*>(
		reinterpret_cast<intptr_t>(a)^
		reinterpret_cast<intptr_t>(b));
}

void insert(Node** head_ref,int data){
	Node* new_node=new Node();
	new_node->data=data;
	new_node->npx=(*head_ref);

	if((*head_ref)!=NULL){
		(*head_ref)->npx=XOR((*head_ref)->npx,new_node);
	}
	
	(*head_ref)=new_node;
}

void printList(Node* head){
	Node* prev=head;
	Node* temp=NULL;
	cout<<"Printing the list in forward direction : ";
	while(head!=NULL){
		cout<<head->data<<" ";
		head=XOR(head->npx,temp);
		temp=prev;
		prev=head;
	}
	cout<<endl;
	prev=temp;
	cout<<"Printing the list in backward direction : ";
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=XOR(temp->npx,head);
		head=prev;
		prev=temp;
	}
	cout<<endl;
}

int main(){

	Node* head=NULL;
	insert(&head,10);
	insert(&head,50);
	insert(&head,30);
	insert(&head,20);
	insert(&head,40);
	insert(&head,60);

	printList(head);

	return 0;
}