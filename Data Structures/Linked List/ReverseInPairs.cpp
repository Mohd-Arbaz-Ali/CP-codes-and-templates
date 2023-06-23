#include"LinkedList.cpp"

Node* reverse(Node* head){
	if(head==NULL || head->next==NULL)
		return NULL;
	Node * temp=NULL;
	temp=head->next;
	head->next=temp->next;
	temp->next=head;
	head=temp;
	head->next->next=reverse(head->next->next);

	return head;
}

int main(){
	Node * head=NULL;
	insertAtHead(&head,10);
	insertAtHead(&head,20);
	insertAtHead(&head,30);
	insertAtHead(&head,40);
	//insertAtHead(&head,50);

	head=reverse(head);
	printList(head);
	
	return 0;
}