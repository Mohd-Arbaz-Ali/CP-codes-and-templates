#include<bits/stdc++.h>
using namespace std;

int task(queue<int>&q,stack<int>&s){
	if(q.empty())
		return INT_MIN;
	while(!q.empty()){
		s.push(q.front());
		q.pop();
	}
	int size=s.size();
	for(int i=0;i<size-1;i++){
		q.push(s.top());
		s.pop();
	}
	return s.top();
}

int main(int argc, char const *argv[])
{
	stack<int >s;
	queue<int>q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	cout<<task(q,s)<<endl;
	return 0;
}