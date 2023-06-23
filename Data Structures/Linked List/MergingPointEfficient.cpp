#include<bits/stdc++.h>
#include"LinkedList.cpp"
using namespace std;

Node* mergingPoint(Node* head1,Node* head2){
	if((head1==NULL)||(head2==NULL))
		return NULL;
	Node* temp1=head1;
	Node* temp2=head2;
	int count1=0;
	while(head1!=NULL){
		count1++;
		head1=head1->next;
	}

	int count2=0;
	while(head2!=NULL){
		count2++;
		head2=head2->next;
	}

	int dif=max(count1,count2)-min(count2,count1);
	if(count1>count2){
		while(dif--){
			temp1=temp1->next;
		}
	}
	else{
		while(dif--){
			temp2=temp2->next;
		}
	}

	while(temp1!=temp2){
		temp2=temp2->next;
		temp1=temp1->next;
	}

	return temp1;

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

	head1->next->next=head->next->next->next;

	cout<<mergingPoint(head1,head)->data<<endl;

	return 0;
}