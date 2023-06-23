#include"CircularLL.cpp"

Node* splitLinkedList(Node** head){
	if((*head)==NULL)
		return NULL;
	Node* slowPtr=(*head);
	Node* fastPtr=(*head);

	while(fastPtr->next!=(*head)){
		fastPtr=fastPtr->next;
		if(fastPtr->next!=(*head))
			fastPtr=fastPtr->next;
		else
			break;
		slowPtr=slowPtr->next;
	}
	Node* temp=slowPtr->next;
	fastPtr->next=temp;
	slowPtr->next=(*head);
	return temp;
}

int main(){

	Node *head=NULL;
	atTail(&head,10);
	atTail(&head,20);
	atTail(&head,30);
	atTail(&head,40);
	atTail(&head,50);
	atTail(&head,60);
	atTail(&head,70);
	atTail(&head,80);

	printList(head);

	Node* head2=splitLinkedList(&head);
	printList(head);
	printList(head2);

	return 0;
}