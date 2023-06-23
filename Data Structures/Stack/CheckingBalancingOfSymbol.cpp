#include<bits/stdc++.h>
using namespace std;

void checkBal(string exp){
	if(exp.length()==0){
		cout<<"Empty expression\n";
		return;
	}
	stack<char> s;
	for(int i=0;i<exp.length();i++){
		if((exp[i]=='(') || (exp[i]=='{') || (exp[i]=='[')){
			s.push(exp[i]);
			continue;
		}
		if(s.empty()){
			cout<<"The expression does'nt have balanced symbol\n";
			return;
		}
		else {
			if(exp[i]==')'){
				if(s.top()=='(')
					s.pop();
				else
					break;
			}
			else if(exp[i]=='}'){
				if(s.top()=='{')
					s.pop();
				else 
					break;
			}
			else if(exp[i]==']'){
				if(s.top()=='[')
					s.pop();
				else
					break;
			}
		}
	}
	if(s.empty()){
		cout<<"The expression has balanced symbol\n";
	}
	else
		cout<<"The expression does'nt have balanced symbol\n";
}

int main(int argc, char const *argv[])
{
	string exp=")))";
	checkBal(exp);
	return 0;
}