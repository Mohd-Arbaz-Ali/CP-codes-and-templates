#include"LinkedList.cpp"

Node *rootNode(Node* head){
	if(head==NULL || head->next==NULL)
		return head;
	int i=1;
	Node *root_node=NULL;
	Node* temp=head;
	for(int n=1;head!=NULL;head=head->next){
		if((i*i)==n){
			root_node=temp;
			temp=temp->next;
			i++;
		}
		n++;
	}
	return root_node;
}

int main(int argc, char const *argv[])
{
	Node* head=NULL;
	insertAtHead(&head,10);
	insertAtHead(&head,9);
	insertAtHead(&head,8);
	insertAtHead(&head,7);
	insertAtHead(&head,6);
	insertAtHead(&head,5);
	insertAtHead(&head,4);
	insertAtHead(&head,3);
	insertAtHead(&head,2);
	insertAtHead(&head,1);
	insertAtHead(&head,111111);
	insertAtHead(&head,11111);
	insertAtHead(&head,1111);
	insertAtHead(&head,111);
	insertAtHead(&head,11);
	insertAtHead(&head,1);
	printList(head);

	cout<<rootNode(head)->data<<endl;

	return 0;
}