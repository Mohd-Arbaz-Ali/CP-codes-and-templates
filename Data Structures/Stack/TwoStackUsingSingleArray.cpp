#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAXSIZE 10;

class twoStack{
	public:
		int top1,top2;
		int capacity;
		int *array;
};

twoStack* createStack(twoStack* S){
	S=new twoStack();
	S->top1=-1;
	S->top2=MAXSIZE;
	S->capacity=MAXSIZE;
	S->array=(int*)malloc(sizeof(int)*S->capacity);
	return S;
}

bool isFull(twoStack* S){
	return (S->top2-S->top1==1);
}
bool isEmpty1(twoStack* S){
	return (S->top1==-1);
}
bool isEmpty2(twoStack* S){
	return (S->top2==S->capacity);
}

void push1(twoStack* S,int data){
	if(isFull(S)){
		cout<<"Overflow\n";
		return;
	}
	S->array[++S->top1]=data;
}
void push2(twoStack* S,int data){
	if(isFull(S)){
		cout<<"Overflow\n";
		return;
	}
	S->array[--S->top2]=data;
}

int pop1(twoStack* S){
	if(isEmpty1(S))
	{
		cout<<"Underflow\n";
		return -1;
	}
	return (S->array[S->top1--]);
}
int pop2(twoStack* S){
	if(isEmpty2(S)){
		cout<<"Underflow\n";
		return -1;
	}
	return (S->array[S->top2++]);
}

int main(int argc, char const *argv[])
{
	twoStack* S=createStack(S);
	push1(S,10);
	push1(S,20);
	push1(S,30);
	push1(S,40);
	push1(S,50);
	push1(S,60);
	push1(S,70);
	cout<<pop1(S)<<endl;
	cout<<pop1(S)<<endl;
	cout<<pop1(S)<<endl;
	cout<<pop1(S)<<endl;
	cout<<pop1(S)<<endl;
	cout<<pop1(S)<<endl;
	cout<<pop1(S)<<endl;
	cout<<pop1(S)<<endl;
	push2(S,10);
	push2(S,20);
	push2(S,30);
	push2(S,40);
	cout<<pop2(S)<<endl;
	cout<<pop2(S)<<endl;
	cout<<pop2(S)<<endl;
	cout<<pop2(S)<<endl;
	return 0;
}