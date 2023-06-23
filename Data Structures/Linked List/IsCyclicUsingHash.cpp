#include<bits/stdc++.h>
#include"LinkedList.cpp"
using namespace std;

int IsCyclic(Node* head){
	unordered_map < Node* , int > umap;
	while(head){
		if(umap[head]==1)
			return head->data;
		umap[head]=1;
		head=head->next;
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
