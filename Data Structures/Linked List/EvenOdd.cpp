#include"LinkedList.cpp"

void EvenOdd(Node** head_ref){
	if((*head_ref)==NULL)	
		return;
	if((*head_ref)->next==NULL)
		return;
	Node* prev=NULL;
	Node* temp=(*head_ref);
	while(temp!=NULL){
		if(temp->data%2==0 && prev!=NULL){
			prev->next=temp->next;
			temp->next=(*head_ref);
			(*head_ref)=temp;
			temp=prev->next;
		}
		else{
			prev=temp;
			temp=temp->next;
		}
	}
}

int main(int argc, char const *argv[])
{
	Node *head=NULL;
	insertAtHead(&head,6);
	insertAtHead(&head,6);
	insertAtHead(&head,4);
	insertAtHead(&head,3);
	insertAtHead(&head,1);
	insertAtHead(&head,1);
	printList(head);

	EvenOdd(&head);
	printList(head);
	return 0;
}