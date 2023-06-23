#include"LinkedList.cpp"

Node* mergingPoint(Node* head1,Node* head2){
	if((head1==NULL)||(head2==NULL))
		return NULL;
	unordered_map< Node*, int > um;
	while(head1!=NULL){
		um[head1]=head1->data;
		head1=head1->next;
	}

	while(head2!=NULL){
		if(um.find(head2)!=um.end())
			return head2;
		head2=head2->next;
	}

	return NULL;
}

int main(){
	Node *head=NULL;
	insertAtTail(&head,10);
	insertAtTail(&head,20);
	insertAtTail(&head,30);
	insertAtTail(&head,40);
	insertAtTail(&head,50);
	insertAtTail(&head,60);

	Node* head1=NULL;
	insertAtTail(&head1,100);
	insertAtTail(&head1,200);

	head1->next->next=head->next->next;

	cout<<mergingPoint(head,head1)->data<<endl;

	return 0;
}