#include"LinkedList.cpp"

Node* middleNode(Node* head){
	 Node* slowPtr=head;
    Node* fastPtr=head;
    if(head==NULL)
        return NULL;
    while(fastPtr!=NULL && fastPtr->next!=NULL){
        slowPtr=slowPtr->next;
        fastPtr=fastPtr->next->next;
    }
    if(fastPtr==NULL)
    	return slowPtr;
    return slowPtr->next;
}

Node* reverse(Node* head){
	Node* prev=NULL;
	Node* temp=head;
	while(head!=NULL){
		temp=temp->next;
		head->next=prev;
		prev=head;
		head=temp;
	}
	return prev;
}

bool palindrome(Node* head){
	Node* temp=middleNode(head);
	temp=reverse(temp);
	while(temp!=NULL){
		if(head->data != temp->data)
			return false;
		head=head->next;
		temp=temp->next;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	Node *head=NULL;
	insertAtTail(&head,80);
	insertAtTail(&head,70);
	insertAtTail(&head,60);
	insertAtTail(&head,50);
	insertAtTail(&head,50);
	insertAtTail(&head,60);
	insertAtTail(&head,70);
	insertAtTail(&head,80);

	cout<<palindrome(head)<<endl;
	return 0;
}