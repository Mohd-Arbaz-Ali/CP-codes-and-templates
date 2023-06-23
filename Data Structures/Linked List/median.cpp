#include"LinkedList.cpp"

float OddOrEven(Node* head){
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
	float res;
	if(flag==1){
		res=(slowPtr->data+slowPtr->next->data)/2.0;
	}
	else
		res=slowPtr->data;
	return res;
}

void median(Node* head){
	if(head==NULL)
		return ;
	cout<<OddOrEven(head)<<endl;
}

int main(){

	Node *head=NULL;
	insertAtTail(&head,10);
	insertAtTail(&head,20);
	insertAtTail(&head,30);
	insertAtTail(&head,40);
	insertAtTail(&head,55);
	insertAtTail(&head,60);
	insertAtTail(&head,70);
	insertAtTail(&head,80);

	printList(head);

	median(head);

	return 0;
}