#include"LinkedList.cpp"

Node* fractionalNode(Node* head,int k){
	if(head==NULL || head->next==NULL){
		return head;
	}
	if(k<=0)
		return NULL;
	int i=1;
	Node* fracNode=NULL;
	Node* temp=head;
	for(;head!=NULL;head=head->next){
		if(i%k==0){
			fracNode=temp;
			temp=temp->next;
		}
		i++;
	}
	return fracNode;
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
	printList(head);

	cout<<fractionalNode(head,5)->data<<endl;

	return 0;
}