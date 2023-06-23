#include"LinkedList.cpp"

bool hasKNodes(Node* head_ref,int k){
	while(head_ref!=NULL && k--){
		head_ref=head_ref->next;
	}
	return (k<=0)? true : false;
}

Node* getKthNode(Node* head_ref,int k){
	if(hasKNodes(head_ref,k)){
		while(--k)
			head_ref=head_ref->next;
		return head_ref;
	}
	return NULL;
}

void reverseKNodesBlocks(Node **temp,int k){
	if((*temp)==NULL){
		return ;
	}
	if(hasKNodes((*temp),k)==false){
		return ;
	}
	Node* head_ref=(*temp);
	(*temp)=getKthNode((*temp),k);
	Node* aux=NULL;
	while(hasKNodes(head_ref,k) && head_ref!=NULL){
		Node* prev=NULL;
		Node* nxt=head_ref;
		int i=0;
		Node* ad=head_ref;
		while(i<k){
			nxt=nxt->next;
			head_ref->next=prev;
			prev=head_ref;
			head_ref=nxt;
			i++;
		}
		//printList(*temp);
		ad->next=head_ref;
		if(aux!=NULL)
			aux->next=prev;
		aux=ad;
		//printList(temp);
	}	
}

int main(){
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
	//printList(head);
	//cout<<getKthNode(head,3)->data<<endl;
	reverseKNodesBlocks(&head,4);
	printList(head);
	return 0;
}