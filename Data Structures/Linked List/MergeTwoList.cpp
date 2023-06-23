#include"LinkedList.cpp"

Node* sortedMerge(Node* head_A, Node* head_B)  
{  
    if(head_A==NULL)    return head_B;
    if(head_B==NULL)    return head_A;
    if(head_B->data>head_A->data){
        swap(head_B,head_A);
    }
    Node* res=head_B;
    while(head_A!=NULL && head_B!=NULL){
        Node* temp=NULL;
        while((head_B!=NULL) && (head_B->data<=head_A->data)){
            temp=head_B;
            head_B=head_B->next;
        }
        temp->next=head_A;
        swap(head_A,head_B);
    }
    
    return res;
}  

Node* sortedMergeRecursive(Node *head_A, Node *head_B){
	if(head_A==NULL)    return head_B;
    if(head_B==NULL)    return head_A;
    Node *res=NULL;
    if(head_A->data<=head_B->data){
    	res=head_A;
    	res->next=sortedMergeRecursive(head_A->next,head_B);
    }
    else{
    	res=head_B;
    	res->next=sortedMergeRecursive(head_A,head_B->next);
    }
    return res;
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
	insertAtTail(&head2,26);
	insertAtTail(&head2,32);
	insertAtTail(&head2,38);
	printList(head2);

	//printList(sortedMerge(head1,head2));
	printList(sortedMergeRecursive(head1,head2));

	return 0;
}