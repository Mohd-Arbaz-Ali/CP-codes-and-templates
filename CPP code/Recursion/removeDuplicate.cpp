#include<iostream>
using namespace std;

string removeDuplicate(string s){
	if(s.length()==0)
		return "";
	string ans=removeDuplicate(s.substr(1));
	if(s[0]==ans[0])
		return ans;
	return s[0]+ans;
}

int main(){
	cout<<removeDuplicate("aaaabbbbeecddd")<<endl;
	return 0;
}