#include<bits/stdc++.h>
using namespace std;

int postfixEvaluation(string pos){
	 stack<int> s;
	for(int i=0;i<pos.length();i++){
		if(isdigit(pos[i]))
			s.push(pos[i]-'0');
		else{
			int val2=s.top();
			s.pop();
			int val1=s.top();
			s.pop();
			switch(pos[i]){
				case '*': s.push(val1*val2);
					break;
				case '/': s.push(val1/val2);
					break;
				case '+': s.push(val1+val2);
					break;
				case '-': s.push(val1-val2);
					break;
			}
		}
	}
	return s.top();
}

int main(int argc, char const *argv[])
{
	string infix="123*+5-";
	cout<<postfixEvaluation(infix)<<endl;
	return 0;
}