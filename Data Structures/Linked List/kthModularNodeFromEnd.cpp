#include"LinkedList.cpp"

Node* modularNode(Node* head,int k){
	if(head==NULL)
		return NULL;
	if(k<=0)
		return NULL;
	Node* temp=head;
	while(k--){
		if(head!=NULL)
			head=head->next;
		else return NULL;
	}
	for(;head!=NULL;head=head->next,temp=temp->next);

	return temp;
}

int main(int argc, char const *argv[])
{
	Node *head=NULL;
	insertAtHead(&head,2);
	insertAtHead(&head,6);
	insertAtHead(&head,4);
	insertAtHead(&head,3);
	insertAtHead(&head,1);
	insertAtHead(&head,8);
	insertAtHead(&head,7);
	insertAtHead(&head,9);
	//insertAtHead(&head,5);
	printList(head);
	cout<<modularNode(head,5)->data<<endl;
	return 0;
}