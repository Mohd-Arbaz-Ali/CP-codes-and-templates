#include<bits/stdc++.h>
using namespace std;

void interLeaving(queue<int>&q){
	if(q.size()%2){
		cout<<"Input an even queue\n";
		return;
	}
	queue<int>temp;
	int size=q.size()/2;
	for(int i=0;i<size;i++){
		temp.push(q.front());
		q.pop();
	}
	for(int i=0;i<size;i++){
		q.push(temp.front());
		temp.pop();
		q.push(q.front());
		q.pop();
	}
}

void interLeavingUsingStack(queue<int>&q){
	if(q.size()%2){
		cout<<"Input an even queue\n";
		return;
	}
	stack<int>s;
	int size=q.size()/2;
	for(int i=0;i<size;i++){
		s.push(q.front());
		q.pop();
	}
	while(!s.empty()){
		q.push(s.top());
		s.pop();
	}
	for(int i=0;i<size;i++){
		q.push(q.front());
		q.pop();
	}
	for(int i=0;i<size;i++){
		s.push(q.front());
		q.pop();
	}
	while(!s.empty()){
		q.push(s.top());
		s.pop();
		q.push(q.front());
		q.pop();
	}
}

void printQ(queue<int>q){
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	queue<int>q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	q.push(7);
	q.push(8);
	q.push(9);
	q.push(10);
	interLeaving(q);
	printQ(q);
	interLeavingUsingStack(q);
	printQ(q);
	return 0;
}