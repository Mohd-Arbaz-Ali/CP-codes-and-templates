#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>& s,int data){
	if(s.empty()){
		s.push(data);
		return;
	}
	int temp=s.top();
	s.pop();
	insertAtBottom(s,data);
	s.push(temp);
}

void reverse(stack<int>& s){
	if(s.empty())
		return;
	int data=s.top();
	s.pop();
	reverse(s);
	insertAtBottom(s,data);
}

void printStack(stack<int> &s){
	if(s.empty())
		return;
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}
}

int main(int argc, char const *argv[])
{
	stack<int > s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	//printStack(s);
	reverse(s);
	printStack(s);
	return 0;
}