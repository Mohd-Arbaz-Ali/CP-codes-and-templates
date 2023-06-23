#include<bits/stdc++.h>
#include<stdlib.h>
#include"DynamicStack.cpp"

class AdvancedStack{
public:
	Stack *elementStack;
	Stack *minStack;
};

AdvancedStack* createAdvStack(){
	AdvancedStack *S=new AdvancedStack();
	S->elementStack=createStack(S->elementStack);
	S->minStack=createStack(S->minStack);
	return S;
}

void AdvPush(AdvancedStack *S,int data){
	push(S->elementStack,data);
	if(!isEmpty(S->minStack) && (Top(S->minStack)<=Top(S->elementStack))){
		push(S->minStack,Top(S->minStack));
	}
	else{
		push(S->minStack,data);
	}
}

int AdvPop(AdvancedStack *S){
	pop(S->minStack);
	return pop(S->elementStack);
}

int getMin(AdvancedStack *S){
	if(!isEmpty(S->minStack))
		return Top(S->minStack);
	return -1;
}

int main(int argc, char const *argv[])
{
	AdvancedStack *S=createAdvStack();	
	AdvPush(S,2);
	AdvPush(S,6);
	AdvPush(S,4);
	AdvPush(S,1);
	AdvPush(S,5);
	//AdvPush(S,1);
	cout<<getMin(S)<<endl;
	AdvPop(S);
	cout<<getMin(S)<<endl;
	AdvPop(S);
	cout<<getMin(S)<<endl;
	AdvPop(S);
	cout<<getMin(S)<<endl;
	AdvPop(S);
	cout<<getMin(S)<<endl;
	AdvPop(S);
	cout<<getMin(S)<<endl;
	return 0;
}