#include"LinkedList.cpp"

Node* modularNode(Node* head,int k){
	if(head==NULL)
		return NULL;
	if(k<=0)
		return NULL;
	int i=1;
	Node* modNode=NULL;
	for(;head!=NULL;head=head->next){
		if(i%k==0)
			modNode=head;
		i++;
	}
	return modNode;
}

int main(int argc, char const *argv[])
{
	Node *head=NULL;
	insertAtHead(&head,2);
	insertAtHead(&head,6);
	insertAtHead(&head,4);
	insertAtHead(&head,3);
	insertAtHead(&head,1);
	insertAtHead(&head,1);
	insertAtHead(&head,7);
	insertAtHead(&head,9);
	//insertAtHead(&head,5);
	printList(head);
	cout<<modularNode(head,3)->data<<endl;
	return 0;
}