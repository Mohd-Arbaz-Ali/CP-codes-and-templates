#include<bits/stdc++.h>
using namespace std;

class Queue{
public:
	stack<int> s1;
	stack<int> s2;
};

void Enqueue(Queue *Q,int data){
	Q->s1.push(data);
}

int isEmpty(Queue *Q){
	return (Q->s1.empty());
}

int Dequeue(Queue *Q){
	if(isEmpty(Q)){
		cout<<"Underflow\n";
		return -1;
	}
	while(!Q->s1.empty()){
		Q->s2.push(Q->s1.top());
		Q->s1.pop();
	}
	int data=Q->s2.top();
	Q->s2.pop();
	while(!Q->s2.empty()){
		Q->s1.push(Q->s2.top());
		Q->s2.pop();
	}
	return data;
}

int main(int argc, char const *argv[])
{
	Queue *Q=new Queue();
	Enqueue(Q,10);
	Enqueue(Q,20);
	Enqueue(Q,30);
	Enqueue(Q,40);
	Enqueue(Q,50);

	cout<<Dequeue(Q)<<endl;
	cout<<Dequeue(Q)<<endl;
	cout<<Dequeue(Q)<<endl;
	cout<<Dequeue(Q)<<endl;
	cout<<Dequeue(Q)<<endl;
	cout<<Dequeue(Q)<<endl;

	return 0;
}