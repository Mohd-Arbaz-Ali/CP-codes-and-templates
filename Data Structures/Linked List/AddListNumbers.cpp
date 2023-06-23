#include"LinkedList.cpp"

Node* addListNumbers(Node* list1,Node* list2){
	if(list2==NULL && list1==NULL){
		return (list1==NULL) ? list2 : list1;
	}
	int x=0,y=0;
	while(list1!=NULL){
		x=x*10+list1->data;
		list1=list1->next;
	}
	while(list2!=NULL){
		y=y*10+list2->data;
		list2=list2->next;
	}
	int z=x+y;
	Node* list3=NULL;
	Node* new_node=NULL;
	while(z>0){
		new_node=new Node();
		new_node->data=z%10;
		new_node->next=NULL;
		new_node->next=list3;
		list3=new_node;
		z=z/10;
	}
	return list3;
}

int main(int argc, char const *argv[])
{
	Node* list1=NULL;
	Node* list2=NULL;
	insertAtHead(&list1,5);
	insertAtHead(&list1,4);
	insertAtHead(&list2,5);
	insertAtHead(&list2,4);
	insertAtHead(&list2,3);
	printList(list1);
	printList(list2);

	Node* list3=addListNumbers(list1,list2);
	printList(list3);

	return 0;
}