#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 15;

class ThreeStacks{
	public:
		int top1,top2;
		int start,top3;
		int capacity;
		int *array;
};

ThreeStacks* createStacks(ThreeStacks* S){
	S=new ThreeStacks();
	S->capacity=MAXSIZE;
	S->top1=-1;
	S->top2=MAXSIZE;
	S->start=S->capacity/3;
	S->top3=S->start-1;
	S->array=(int*)malloc(sizeof(int) * S->capacity);
	return S;
}

void push1(ThreeStacks* S,int data){
	if((S->start-S->top1==1) && (S->top2-S->top3==1)){
		cout<<"Stack1 Overflow\n";
		return;
	}
	if(S->start-S->top1==1){
		S->top3++;
		int temp=S->top3;
		while(temp!=S->start){
			S->array[temp]=S->array[temp-1];
			temp--;
		}
		S->start++;
	}
	S->array[++S->top1]=data;
}
void push2(ThreeStacks* S,int data){
	if((S->top2-S->top3==1) && (S->start-S->top1==1)){
		cout<<"Stack2 Overflow\n";
		return;
	}
	if(S->top2-S->top3==1){
		S->start--;
		int temp=S->start;
		while(temp!=S->top3){
			S->array[temp]=S->array[temp+1];
			temp++;
		}
		S->top3--;
	}
	S->array[--S->top2]=data;
}
void push3(ThreeStacks* S,int data){
	if((S->start-S->top1==1) && (S->top2-S->top3==1)){
		cout<<"Stack3 Overflow\n";
		return;
	}
	if(S->top2-S->top3==1){
		S->start--;
		int temp=S->start;
		while(temp!=S->top3){
			S->array[temp]=S->array[temp+1];
			temp++;
		}
		S->top3--;
	}
	S->array[++S->top3]=data;
}

void push(ThreeStacks* S,int data,int stackNum){
	if(stackNum==1)
		push1(S,data);
	else if(stackNum==2)
		push2(S,data);
	else if(stackNum==3)
		push3(S,data);
}

int pop1(ThreeStacks* S){
	if(S->top1==-1){
		cout<<"Stack1 Underflow ";
		return INT_MIN;
	}
	return (S->array[S->top1--]);
}
int pop2(ThreeStacks* S){
	if(S->top2==S->capacity){
		cout<<"Stack2 Underflow ";
		return INT_MIN;
	}
	return (S->array[S->top2++]);
}
int pop3(ThreeStacks* S){
	if(S->start-S->top3==1){
		cout<<"Stack3 Underflow ";
		return INT_MIN;
	}
	return (S->array[S->top3--]);
}

int pop(ThreeStacks* S,int stackNum){
	if(stackNum==1)
		return pop1(S);
	else if(stackNum==2)
		return pop2(S);
	else if(stackNum==3)
		return pop3(S);
	return INT_MIN;
}

int main(int argc, char const *argv[])
{
	ThreeStacks *S=createStacks(S);
	push(S,10,1);
	push(S,20,1);
	push(S,30,1);
	push(S,40,2);
	push(S,60,2);
	push(S,70,2);
	push(S,80,2);
	push(S,1,3);
	push(S,2,3);
	push(S,3,3);
	push(S,4,3);
	push(S,5,3);
	push(S,6,3);
	push(S,30,1);
	push(S,50,2);
	push(S,80,1);

	cout<<"Stack1 "<<pop(S,1)<<endl;
	cout<<"Stack1 "<<pop(S,1)<<endl;
	cout<<"Stack1 "<<pop(S,1)<<endl;
	cout<<"Stack1 "<<pop(S,1)<<endl;
	cout<<"Stack1 "<<pop(S,1)<<endl;
	cout<<"Stack2 "<<pop(S,2)<<endl;
	cout<<"Stack2 "<<pop(S,2)<<endl;
	cout<<"Stack2 "<<pop(S,2)<<endl;
	cout<<"Stack2 "<<pop(S,2)<<endl;
	cout<<"Stack2 "<<pop(S,2)<<endl;
	cout<<"Stack3 "<<pop(S,3)<<endl;
	cout<<"Stack3 "<<pop(S,3)<<endl;
	cout<<"Stack3 "<<pop(S,3)<<endl;
	cout<<"Stack3 "<<pop(S,3)<<endl;
	cout<<"Stack3 "<<pop(S,3)<<endl;
	cout<<"Stack3 "<<pop(S,3)<<endl;
	cout<<"Stack3 "<<pop(S,3)<<endl;
	cout<<"Stack2 "<<pop(S,2)<<endl;
	return 0;
}