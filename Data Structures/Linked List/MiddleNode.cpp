#include"LinkedList.cpp"

/*Node* middleNode(Node* head){
	if(head==NULL)
		return NULL;
	Node* slowPtr=head;
	Node* fastPtr=head;

	while(fastPtr->next!=NULL){
		fastPtr=fastPtr->next;
		if(fastPtr->next!=NULL)
			fastPtr=fastPtr->next;
		else
			break;
		slowPtr=slowPtr->next;
	}
	return slowPtr;
}*/
Node* middleNode(Node* head){
	 Node* slowPtr=head;
    Node* fastPtr=head;
    if(head==NULL)
        return NULL;
    while(fastPtr!=NULL && fastPtr->next!=NULL){
        slowPtr=slowPtr->next;
        fastPtr=fastPtr->next->next;
    }
    return slowPtr;
}

int main(){

	Node *head=NULL;
	insertAtTail(&head,10);
	insertAtTail(&head,20);
	insertAtTail(&head,30);
	insertAtTail(&head,40);
	insertAtTail(&head,50);
	insertAtTail(&head,60);
	insertAtTail(&head,70);
	//insertAtTail(&head,80);

	printList(head);

	cout<<middleNode(head)->data<<endl;

	return 0;
}