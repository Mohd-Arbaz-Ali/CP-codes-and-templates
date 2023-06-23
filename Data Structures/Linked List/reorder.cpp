#include"ReverseSinglyLinkedList.cpp"

void reorderList(Node* head){
	if(head==NULL)
		return ;
	Node* slowPtr=head;
	Node* fastPtr=head;
	Node*prev=NULL;
	while(fastPtr!=NULL && fastPtr->next!=NULL){
		prev=slowPtr;
		slowPtr=slowPtr->next;
		fastPtr=fastPtr->next->next;
	}
	if(fastPtr==NULL){
		prev->next=NULL;
		slowPtr=reverseList(slowPtr);
	}
	else{
		prev=slowPtr;
		slowPtr=slowPtr->next;
		prev->next=NULL;
		slowPtr=reverseList(slowPtr);
	}
	Node* temp=head;
	while(temp!=NULL && slowPtr!=NULL){
		prev=temp;
		temp=temp->next;
		prev->next=slowPtr;
		prev=slowPtr;
		slowPtr=slowPtr->next;
		prev->next=temp;
	}
}

int main(){

	Node *head=NULL;
	insertAtHead(&head,10);
	insertAtHead(&head,9);
	insertAtHead(&head,1);
	insertAtHead(&head,15);
	insertAtHead(&head,11);
	insertAtHead(&head,5);
	insertAtHead(&head,20);
	insertAtHead(&head,30);
	printList(head);

	reorderList(head);
	printList(head);

	return 0;
}