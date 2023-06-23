#include<bits/stdc++.h>
using namespace std;

string removeDuplicates(string str,stack<char>& s){
	if(str[0]=='\0' && str[1]=='\0')
		return str;
	//cout<<str<<endl;
	if(str[0]==str[1])
		str=removeDuplicates(str.substr(2,str.size()-2),s);
	else{
		if(!s.empty() && s.top()==str[0]){
			s.pop();
					}
		else{
			s.push(str[0]);
		}
		str=removeDuplicates(str.substr(1,str.size()-1),s);
	}
	if(!s.empty()){
		str=s.top()+str;
		//cout<<s.top()<<endl;
		s.pop();
	}
	//cout<<str<<endl;
	return str;
}

int main(int argc, char const *argv[])
{
	stack<char> s;
	string str="careermonk";
	cout<<removeDuplicates(str,s)<<endl;
	string str1="mississippi";
	cout<<removeDuplicates(str1,s)<<endl;
	return 0;
}