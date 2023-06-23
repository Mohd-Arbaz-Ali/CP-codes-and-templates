#include<bits/stdc++.h>
using namespace std;

class MultiStacks{
	public:
		int * top;
		int *next;
		int *array;
		int capacity;
		int free;
};

MultiStacks* createStack(MultiStacks* S,int capacity,int k){
	S=new MultiStacks();
	S->array=new int[capacity];
	S->capacity=capacity;
	S->top=new int[k];
	S->next=new int[capacity];
	for(int i=0;i<k;i++){
		S->top[i]=-1;
	}
	for(int i=0;i<capacity;i++)
		S->next[i]=i+1;
	S->next[capacity-1]=-1;
	S->free=0;
	return S;
}

void push(MultiStacks* S,int sn,int data){
	if(S->free==-1){
		cout<<"Overflow\n";
		return;
	}
	int i=S->free;
	S->array[S->free]=data;
	S->free=S->next[S->free];
	S->next[i]=S->top[sn];
	S->top[sn]=i;
}

int pop(MultiStacks* S,int sn){
	if(S->top[sn]==-1){
		cout<<"Underflow ";
		return INT_MIN;
	}
	int i=S->top[sn];
	S->top[sn]=S->next[S->top[sn]];
	S->next[i]=S->free;
	S->free=i;
	return S->array[i];
}

int main(int argc, char const *argv[])
{
	MultiStacks *S=createStack(S,10,4);
	push(S,0,10);
	push(S,0,20);
	push(S,0,30);
	push(S,2,40);
	push(S,2,50);
	push(S,3,60);
	push(S,1,70);
	push(S,2,80);
	push(S,1,90);
	push(S,3,1);
	push(S,3,2);
	cout<<pop(S,0)<<endl;
	cout<<pop(S,0)<<endl;
	cout<<pop(S,0)<<endl;
	cout<<pop(S,1)<<endl;
	cout<<pop(S,1)<<endl;
	cout<<pop(S,2)<<endl;
	cout<<pop(S,2)<<endl;
	cout<<pop(S,2)<<endl;
	cout<<pop(S,3)<<endl;
	cout<<pop(S,3)<<endl;
	cout<<pop(S,3)<<endl;
	return 0;
}