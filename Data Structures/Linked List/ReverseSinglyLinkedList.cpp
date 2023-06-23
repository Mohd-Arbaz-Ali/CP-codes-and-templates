#include"LinkedList.cpp"

Node* reverseList(Node* head){
	Node* prev=NULL;
	Node* temp=NULL;
	while(head){
		temp=head->next;
		head->next=prev;
		prev=head;
		head=temp;
	}
	return prev;
}

Node *reverseRecursive(Node* head){
	if(head==NULL){
		return NULL;
	}
	if(head->next==NULL){
		return head;
	}
	Node* temp=head->next;
	head->next=NULL;
	Node* prev=reverseRecursive(temp);
	temp->next=head;
	return prev;
}

/*int main(){
	Node *head=NULL;
	insertAtTail(&head,10);
	insertAtTail(&head,20);
	insertAtTail(&head,30);
	insertAtTail(&head,40);
	insertAtTail(&head,50);
	insertAtTail(&head,60);

	printList(head);

	//head=reverseList(head);
	head=reverseRecursive(head);
	printList(head);

	return 0;
}*/