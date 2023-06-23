#include<bits/stdc++.h>
using namespace std;

class Queue{
public:
	int front,rear,size;
	int *arr;
};

Queue* createQueue(Queue* Q,int capacity){
	Q=new Queue();
	Q->size=capacity;
	Q->front=-1;
	Q->rear=-1;
	Q->arr=new int[capacity];
	if(!Q->arr)
		return NULL;
	return Q;
}

void Enqueue(Queue* S,int data){
	if((S->front==0 && S->rear==S->size-1) || (S->front==S->rear+1)){
		cout<<"Overflow\n";
		return;
	}
	if(S->rear==-1){
		S->front=S->rear=0;
		S->arr[S->rear]=data;
	}
	else if(S->rear==S->size-1){
		S->rear=0;
		S->arr[S->rear]=data;
	}
	else{
		S->arr[++S->rear]=data;
	}
}

int Dequeue(Queue* Q){
	if(Q->front==-1){
		cout<<"Underflow ";
		return INT_MIN;
	}
	int num;
	if(Q->front==Q->rear)
	{
		num=Q->arr[Q->front];
		Q->front=-1;
		Q->rear=-1;
		return num;
	}
	if(Q->front==Q->size-1){
		num=Q->arr[Q->front];
		Q->front=0;
		return num;
	}
	return Q->arr[Q->front++];
}
int Size(Queue* Q){
	if(Q->rear>=Q->front && Q->front!=-1)
		return ( (Q->rear-Q->front)+1);
	else if(Q->front==-1){
		return 0;
	}
	return ((Q->size-(Q->front-Q->rear))+1);
}

int main(int argc, char const *argv[])
{
	Queue* Q=createQueue(Q,6);	
	Enqueue(Q,10);
	Enqueue(Q,20);
	Enqueue(Q,30);
	Enqueue(Q,40);
	Enqueue(Q,50);
	Enqueue(Q,60);
	Dequeue(Q);
	Dequeue(Q);
	Enqueue(Q,1);
	Enqueue(Q,1);
	Dequeue(Q);
	Dequeue(Q);
	Dequeue(Q);
	Dequeue(Q);
	Dequeue(Q);
	Dequeue(Q);
	
	cout<<Size(Q)<<endl;

	return 0;
}