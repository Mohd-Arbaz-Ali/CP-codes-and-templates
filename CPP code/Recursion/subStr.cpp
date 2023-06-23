#include<iostream>
#include<string>
using namespace std;

string subStr(string str,string ans){
	if(str.length()==0){
		cout<<ans<<endl;
		return "";
	}

	char ch=str[0];
	int code=ch;
	subStr(str.substr(1),ans);
	subStr(str.substr(1),ans+ch);
	subStr(str.substr(1),ans+ to_string(code));

	return ans;
}

int main(int argc, char const *argv[])
{
	subStr("AB","");
	return 0;
}