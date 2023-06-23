#include<bits/stdc++.h>
#include"LinkedList.cpp"
using namespace std;

void push(Node** top,int data){
	insertAtHead(top,data);
}

void pop(Node** top){
	if((*top)==NULL){
		cout<<"Stack is empty\n";
		return;
	}
	deleteAtHead(top);
}

void printStack(Node* top){
	printList(top);
}
/*int main(int argc, char const *argv[])
{
	Node* top=NULL;
	push(&top,10);
	push(&top,20);
	push(&top,30);
	printStack(top);
	pop(&top);
	printStack(top);
	pop(&top);
	printStack(top);
	pop(&top);
	printStack(top);
	pop(&top);
	printStack(top);
	return 0;
}*/