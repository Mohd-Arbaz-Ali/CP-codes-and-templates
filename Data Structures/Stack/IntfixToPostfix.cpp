#include<bits/stdc++.h>
using namespace std;

int precedence(char ch){
	if(ch=='^')
		return 3;
	else if(ch=='*' || ch=='/')
		return 2;
	else if(ch=='+' || ch=='-')
		return 1;
	return -1;
}

string InfixToPostfix(string exp){
	stack<char> s;
	string pos;
	for(int i=0;i<exp.length();i++){
		if((exp[i]>='a' && exp[i]<='z') || (exp[i]>='A' && exp[i]<='Z')){
			pos=pos+exp[i];
		}
		else if(exp[i]=='('){
			s.push(exp[i]);
		}
		else if(exp[i]==')'){
			while(!s.empty() && s.top()!='('){
				pos=pos+s.top();
				s.pop();
			}
			s.pop();
		}
		else{
			while((!s.empty()) && precedence(exp[i])<=precedence(s.top())){
			    pos=pos+s.top();
			    s.pop();
			}
			s.push(exp[i]);
		}
	}
	while(!s.empty()){
		pos=pos+s.top();
		s.pop();
	}
	return pos;
}

int main(int argc, char const *argv[])
{
	string infix="a*b-(c+d)+e";
	cout<<InfixToPostfix(infix)<<endl;
	return 0;
}