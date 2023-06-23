#include<bits/stdc++.h>
using namespace std;

int precedence(char ch){
	if(ch=='*' || ch=='/')
		return 2;
	else if(ch=='+' || ch=='-')
		return 1;
	return -1;
}

int calculation(int val1,int val2,char opr){
	switch(opr){
				case '*': return (val1*val2);
					break;
				case '/': return (val1/val2);
					break;
				case '+': return (val1+val2);
					break;
				case '-': return (val1-val2);
					break;
	}
	return 0;
}

int infixEvaluation(string infix){
	if(infix.size()<3)
		return INT_MIN;
	stack<char> opt;
	stack<int >opd;
	int val1,val2;
	char opr;
	for(int i=0;i<infix.size();i++){
		if(infix[i]==' ')
			continue;
		if(isdigit(infix[i])){
			int val=0;
			while(i<infix.size() && isdigit(infix[i])){
				val=(val*10) + (infix[i]-'0');
				i++;
			}
			opd.push(val);
			i--;
		}
		else if(infix[i]=='(')
			opt.push(infix[i]);
		else if(infix[i]==')'){
			if(!opt.empty()){
				while(!opt.empty() && opt.top()!='('){
					val2=opd.top();
					opd.pop();
					val1=opd.top();
					opd.pop();
					opr=opt.top();
					opt.pop();
					opd.push(calculation(val1,val2,opr));
				}
				opt.pop();
			}
			else return INT_MIN;
		}
		else{
			while(!opt.empty() && precedence(infix[i])<=precedence(opt.top())){
					val2=opd.top();
					opd.pop();
					val1=opd.top();
					opd.pop();
					opr=opt.top();
					opt.pop();
					opd.push(calculation(val1,val2,opr));
			}
			opt.push(infix[i]);
		}
	}
	while(!opt.empty()){
					val2=opd.top();
					opd.pop();
					val1=opd.top();
					opd.pop();
					opr=opt.top();
					opt.pop();
					opd.push(calculation(val1,val2,opr));
	}
	return opd.top();
}

int main(){
	string infix="2+3*11-5-5";
	cout<<infixEvaluation(infix)<<endl;
	return 0;
}