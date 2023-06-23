#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAXSIZE 10;

class Stack
{
public:
	int top;
	int capacity;
	int *array;
};

Stack* createStack(Stack *S){
	S=new Stack();
	S->top=-1;
	S->capacity=MAXSIZE;
	S->array=(int*)malloc(sizeof(int)*S->capacity);
	if(!S->array)
		return NULL;
	return S;
}

bool isFull(Stack *S){
	return (S->top==S->capacity-1);
}

void push(Stack* S,int data){
	if(isFull(S))
		cout<<"Stack Overflow\n";
	else
		S->array[++(S->top)]=data;
}

bool isEmpty(Stack *S){
	return (S->top==-1);
}

int pop(Stack* S){
	if(isEmpty(S)){
		cout<<"Stack Underflow";
		return INT_MIN;
	}
	return S->array[S->top--];
}

void deleteStack(Stack* S){
	if(S){
		if(S->array)
			free(S->array);
		free(S);
	}
}

int Top(Stack *S){
	return S->array[S->top];
}

int Size(Stack *S){
	return (S->top)+1;
}

int main(int argc, char const *argv[])
{
	Stack *S=NULL;
	S=createStack(S);
	push(S,10);
	push(S,20);
	push(S,30);
	push(S,40);
	push(S,50);
	push(S,50);
	push(S,50);
	push(S,50);
	push(S,50);
	push(S,50);
	push(S,50);
	cout<<Top(S)<<endl;
	cout<<Size(S)<<endl;
	cout<<pop(S)<<endl;
	cout<<pop(S)<<endl;
	cout<<pop(S)<<endl;
	cout<<pop(S)<<endl;
	cout<<pop(S)<<endl;
	cout<<pop(S)<<endl;
	deleteStack(S);
	return 0;
}