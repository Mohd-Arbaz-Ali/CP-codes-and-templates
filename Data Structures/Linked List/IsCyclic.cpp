#include<bits/stdc++.h>
#include"LinkedList.cpp"
using namespace std;

int IsCyclic(Node* head){
	Node* slow_ptr=head;
	Node* fast_ptr=head;
	int loopExist=0;
	while(slow_ptr && fast_ptr && fast_ptr->next){
		slow_ptr=slow_ptr->next;
		fast_ptr=fast_ptr->next->next;
		if(slow_ptr==fast_ptr){
			loopExist=1;
			break;
		}
	}
	if(loopExist==1){
		slow_ptr=head;
		while(slow_ptr!=fast_ptr){
			slow_ptr=slow_ptr->next;
			fast_ptr=fast_ptr->next;
		}
		return slow_ptr->data;
	}
	return 0;
}

int main(){
	Node *head=NULL;
	insertAtTail(&head,10);
	insertAtTail(&head,20);
	insertAtTail(&head,30);
	insertAtTail(&head,40);
	insertAtTail(&head,50);
	insertAtTail(&head,60);
	insertAtTail(&head,70);
	insertAtTail(&head,80);

	Node* temp=head;
	while(temp->next!=NULL)	temp=temp->next;

	temp->next=head->next->next;

	cout<<IsCyclic(head)<<endl;

	return 0;
}
