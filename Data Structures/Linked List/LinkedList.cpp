#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:
		int data;	
		Node *next;
};

Node* createNode(int data){
	Node* new_node=new Node();
	new_node->data=data;
	new_node->next=NULL;
	return new_node;
}

void insertAtHead(Node **head_ref,int data){
	Node* new_node=createNode(data);
	new_node->next=*head_ref;
	*head_ref=new_node;
}
void deleteAtHead(Node** head_ref){
	Node *temp=*head_ref;
	Node *prev=*head_ref;
	if(*head_ref==NULL)
		return;
	prev=prev->next;
	*head_ref=prev;
	free(temp);
}

void insertAtTail(Node** head_ref,int data){
	Node *new_node=createNode(data);
	Node *last=*head_ref;
	if(*head_ref==NULL){
		*head_ref=new_node;
		return;
	}
	else{
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=new_node;
	}
}
void deleteAtTail(Node *temp){
	Node *prev=temp;
	if(temp==NULL)
		return;
	while(temp->next!=NULL){
		prev=temp;
		temp=temp->next;
	}
	prev->next=NULL;
	free(temp);
}

void insertPos(Node **head,int position,int data){
	Node *new_node=createNode(data);
	Node *temp=*head;
	Node *prev;
	if(position==1)
		insertAtHead(head,data);
	else{
		int k=1;
		while((temp!=NULL)&&(k<position)){
			prev=temp;
			temp=temp->next;
			k++;
		}
		if(temp==NULL)
			cout<<"Position does not exist\n";
		else{
			new_node->next=temp;
			prev->next=new_node;
		}
	}
}

void deletePos(Node **head,int position){
	Node *prev;
	Node *temp=*head;
	if(position==1)
		deleteAtHead(head);
	else{
		int k=1;
		while((temp!=NULL)&&(k<position)){
			prev=temp;
			temp=temp->next;
			k++;
		}
		if(temp==NULL)
			cout<<"Position does not exist\n";
		else{
			prev->next=temp->next;
			free(temp);
		}
	}
}

void printList(Node *temp){
	while(temp!=NULL){
		cout<<temp->data<<"  ";
		temp=temp->next;
	}
	cout<<endl;
}

/*int main(int argc, char const *argv[])
{
	Node *head=NULL;
	insertAtHead(&head,10);
	insertAtHead(&head,20);
	insertAtHead(&head,30);
	insertAtHead(&head,40);
	insertAtHead(&head,50);
	printList(head);
	deleteAtHead(&head);
	printList(head);
	insertAtTail(&head,100);
	insertAtTail(&head,200);
	printList(head);
	deleteAtTail(head);
	printList(head);
	insertPos(&head,4,55);
	insertPos(&head,1,105);
	printList(head);
	deletePos(&head,1);
	deletePos(&head,3);
	printList(head);
	deletePos(&head,8);
	return 0;
}*/