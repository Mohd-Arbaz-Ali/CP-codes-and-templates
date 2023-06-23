#include<iostream>
using namespace std;

string removeAllX(string s){
	if(s.length()==0)
		return "";
	char ch=s[0];
	string ans=removeAllX(s.substr(1));
	if(ch=='x')
		return (ans+ch);
	return (ch+ans);
}

int main(){
	cout<<removeAllX("xxarbazxalix")<<endl;
	return 0;
}