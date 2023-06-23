#include<iostream>
using namespace std;
template<typename T>
class Stack{
	public:
		int data;
		Stack* next;
};

void push(Stack **top,int data){
	Stack* new_node=new Stack();
	new_node->data=data;
	new_node->next=NULL;
	if((*top)==NULL)
		(*top)=new_node;
	else{
		new_node->next=(*top);
		(*top)=new_node;
	}
}

bool isEmpty(Stack *top){
	return (top==NULL);
}

int pop(Stack **top){
	if(isEmpty(*top)){
		cout<<"Stack Underflow\n";
		return INT_MIN;
	}
	Stack *temp=(*top);
	(*top)=(*top)->next;
	return temp->data;
}
int Top(Stack *top){
	if(top==NULL)
		return INT_MIN;
	return top->data;
}

void deleteStack(Stack *top){
	Stack* temp=NULL;
	while(top!=NULL){
		temp=top;
		top=top->next;
		free(temp);
	}
}

int main(){
	Stack *top=NULL;
	push(&top,10);
	push(&top,20);
	push(&top,30);
	push(&top,40);
	push(&top,50);
	cout<<pop(&top)<<endl;
	cout<<pop(&top)<<endl;
	cout<<pop(&top)<<endl;
	cout<<pop(&top)<<endl;
	cout<<pop(&top)<<endl;
	cout<<pop(&top)<<endl;
	cout<<Top(top)<<endl;
	deleteStack(top);
	//cout<<Top(top);
	return 0;
}