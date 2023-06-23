#include<bits/stdc++.h>
using namespace std;

void reverseK(queue<int>&q,int k){
	if(k>q.size() || q.empty())
		return;
	stack<int>s;
	for(int i=0;i<k;i++){
		s.push(q.front());
		q.pop();
	}
	while(!s.empty()){
		q.push(s.top());
		s.pop();
	}
	for(int i=0;i<(q.size()-k);i++){
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
	reverseK(q,4);
	printQ(q);
	return 0;
}