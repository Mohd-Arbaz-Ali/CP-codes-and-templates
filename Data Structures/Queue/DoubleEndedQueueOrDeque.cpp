#include<bits/stdc++.h>
using namespace std;

class Deque{
	int front,rear;
	int size;
	int *arr;
public:
	Deque(int size){
		front=-1;
		rear=0;
		this->size=size;
		arr=(int*)malloc(sizeof(arr)*size);
	}
	void insertFront(int data);
	void insertBack(int data);
	void deleteFront();
	void deleteBack();
	bool isFull();
	bool isEmpty();
	int getFront();
	int getBack();
};

bool Deque:: isFull(){
	return ((rear==size-1 && front==0) || front==rear+1);
}

bool Deque:: isEmpty(){
	return (front==-1);
}

void Deque:: insertBack(int data){
	if(isFull()){
		cout<<"Overflow\n";
		return;
	}
	if(front==-1){
		front=rear=0;
		arr[rear]=data;
	}
	else if(rear==size-1){
		rear=0;
		arr[rear]=data;
	}
	else
		arr[++rear]=data;
	//cout<<arr[rear]<<endl;
}

void Deque:: insertFront(int data){
	if(isFull()){
		cout<<"Overflow\n";
		return;
	}
	if(front==-1){
		rear=front=0;
		arr[front]=data;
	}
	else if(front==0){
		front=size-1;
		rear=0;
		arr[front]=data;
	}
	else
		arr[--front]=data;
	//cout<<arr[front]<<endl;
}

void Deque:: deleteFront(){
	if(isEmpty()){
		cout<<"Underflow\n";
		return;
	}
	if(front==rear){
		front=-1;
		rear=-1;
	}
	else if(front==size-1){
		front=0;
	}
	else
		front++;
	//cout<<arr[front]<<endl;
}

void Deque:: deleteBack(){
	if(isEmpty()){
		cout<<"Underflow\n";
		return;
	}
	if(front==rear){
		front=rear=-1;
	}
	else if(rear==0){
		rear=size-1;
	}
	else
		rear--;
	//cout<<arr[rear]<<endl;
}

int Deque:: getBack(){
	if(isEmpty())
		return INT_MIN;
	return arr[rear];
}

int Deque:: getFront(){
	if(isEmpty())
		return INT_MIN;
	return arr[front];
}

int main(int argc, char const *argv[])
{
	Deque Q(5);
	Q.insertFront(10);
	Q.insertFront(20);
	Q.insertFront(20);
	Q.insertFront(80);
	Q.insertBack(30);
	Q.insertBack(40);
	cout<<Q.getFront()<<endl;
	cout<<Q.getBack()<<endl;
	Q.deleteFront();
	Q.deleteFront();
	Q.insertBack(50);
	Q.insertBack(60);
	Q.insertBack(70);
	Q.deleteFront();
	Q.deleteBack();
	cout<<Q.getFront()<<endl;
	cout<<Q.getBack()<<endl;

	return 0;
}