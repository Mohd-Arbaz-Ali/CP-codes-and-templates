#include"LinkedList.cpp"

Node* OddOrEven(Node* head){
	if(head==NULL)
		return NULL;
	Node* slowPtr=head;
	Node* fastPtr=head;
	int flag=0;
	while(fastPtr->next!=NULL){
		fastPtr=fastPtr->next;
		if(fastPtr->next!=NULL)
			fastPtr=fastPtr->next;
		else{
			flag=1;
			break;
		}
		slowPtr=slowPtr->next;
	}
	if(flag==1)
		cout<<"List is even\n";
	else
		cout<<"List is odd\n";
	return slowPtr;
}

/*int main(){

	Node *head=NULL;
	insertAtTail(&head,10);
	insertAtTail(&head,20);
	insertAtTail(&head,30);
	insertAtTail(&head,40);
	insertAtTail(&head,50);
	insertAtTail(&head,60);
	insertAtTail(&head,70);
	insertAtTail(&head,80);

	printList(head);

	cout<<OddOrEven(head)->data<<endl;

	return 0;
}*/