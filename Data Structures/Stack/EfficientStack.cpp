#include<bits/stdc++.h>
using namespace std;

class DLL
{
public:
	DLL* prev;
	DLL* next;
	int data;
};
class Stack{
public:
	DLL* head;
	DLL* mid;
	int count;
};

Stack* createStack(Stack* S){
	S=new Stack();
	S->head=NULL;
	S->mid=NULL;
	S->count=0;
	return S;
}

void push(Stack** S,int data){
	DLL* new_node=new DLL();
	new_node->data=data;
	new_node->prev=NULL;
	new_node->next=(*S)->head;
	if(((*S)->head)!=NULL)
		((*S)->head)->prev=new_node;
	((*S)->head)=new_node;
	((*S)->count)++;
	if(((*S)->count)==1){
		(*S)->mid=(*S)->head;
	}
	else if(((*S)->count)%2){
		(*S)->mid=((*S)->mid)->prev;
	}
}

int pop(Stack** S){
	if((*S)->count==0){
		cout<<"Stack Undeflow";
		return -1;
	}
	int num=(*S)->head->data;
	DLL* temp=(*S)->head;
	(*S)->head=(*S)->head->next;
	(*S)->head->prev=NULL;
	(*S)->count--;
	free(temp);
	if((*S)->count==0)
		(*S)->mid=NULL;
	else if((*S)->count%2==0){
		(*S)->mid=((*S)->mid)->next;
	}
	return num;
}

int middle(Stack *S){
	if(S->mid==NULL){
		cout<<"Stack is empty";
		return INT_MIN;
	}
	return S->mid->data;
}

void deleteMiddle(Stack **S){
	if((*S)->mid==NULL)
		return;
	DLL* temp=(*S)->mid;
	if((*S)->count<=2){
		(*S)->mid=(*S)->mid->prev;
	}
	else if((*S)->count%2){
		(*S)->mid=(*S)->mid->next;
		temp->prev->next=(*S)->mid;
		(*S)->mid->prev=temp->prev;
	}
	else{
		(*S)->mid=(*S)->mid->prev;
		(*S)->mid->next=temp->next;
		temp->next->prev=(*S)->mid;
	}
	free(temp);
	(*S)->count--;
	if((*S)->count==0)
		(*S)->head=NULL;
}

int main(int argc, char const *argv[])
{
	Stack* S=createStack(S);
	push(&S,10);
	push(&S,20);
	push(&S,40);
	push(&S,50);
	push(&S,60);
	push(&S,70);
	push(&S,80);
	push(&S,90);
	cout<<pop(&S)<<endl;
	cout<<pop(&S)<<endl;
	cout<<pop(&S)<<endl;
	cout<<pop(&S)<<endl;
	cout<<pop(&S)<<endl;
	//cout<<pop(&S)<<endl;
	cout<<middle(S)<<endl;
	deleteMiddle(&S);
	cout<<middle(S)<<endl;
	deleteMiddle(&S);
	cout<<middle(S)<<endl;
	deleteMiddle(&S);
	cout<<middle(S)<<endl;
	cout<<pop(&S)<<endl;
	return 0;
}