#include"LinkedList.cpp"

void printCommonNodes(Node* head1,Node* head2){
	if(head1==NULL || head2==NULL)
		return ;
	if(head1->data>head2->data){
		swap(head1,head2);
	}
	while(head1!=NULL && head2!=NULL){
		if(head1->data<head2->data){
			head1=head1->next;
		}
		else if(head1->data==head2->data){
			cout<<head1->data<<endl;
			head1=head1->next;
		}
		else{
			swap(head1,head2);
		}
	}
}

int main(){
	Node* head1=NULL;
	Node* head2=NULL;

	insertAtTail(&head1,15);
	insertAtTail(&head1,19);
	insertAtTail(&head1,25);
	insertAtTail(&head1,35);
	insertAtTail(&head1,39);
	printList(head1);

	insertAtTail(&head2,16);
	insertAtTail(&head2,21);
	insertAtTail(&head2,25);
	insertAtTail(&head2,39);
	insertAtTail(&head2,38);
	printList(head2);

	//printList(sortedMerge(head1,head2));
	printCommonNodes(head1,head2);

	return 0;
}