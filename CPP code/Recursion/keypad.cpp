#include<iostream>
using namespace std;

string keys[]={"","./","abc","def","ghi","jkl","mno","pqr","stuv","wxyz"};

void keypad(string s,string ans){
	if(s.length()==0)
	{
		cout<<ans<<endl;
		return ;
	}
	char ch=s[0];
	string code=keys[ch-'0'];
	string res=s.substr(1);
	for(int i=0;i<code.length();i++){
		keypad(res,ans+code[i]);
	}
}

int main(int argc, char const *argv[])
{
	keypad("23","");
	return 0;
}