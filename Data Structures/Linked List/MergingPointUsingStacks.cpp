#include<bits/stdc++.h>
#include"LinkedList.cpp"
using namespace std;

Node* mergingPoint(Node* head1,Node* head2){
	if((head1==NULL)||(head2==NULL))
		return NULL;
	stack <Node*> s1;
	while(head1!=NULL){
		s1.push(head1);
		head1=head1->next;
	}

	stack <Node*> s2;
	while(head2!=NULL){
		s2.push(head2);
		head2=head2->next;
	}
	Node *temp=NULL;
	while(s1.top()==s2.top()){
		temp=s1.top();
		s1.pop();
		s2.pop();
	}

	return temp;

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

	cout<<mergingPoint(head,head1)->data<<endl;

	return 0;
}