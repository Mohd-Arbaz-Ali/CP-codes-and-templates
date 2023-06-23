#include <bits/stdc++.h>
#include<string>
using namespace std;

string reverse(string str,int st,int end){
    
    while(st<end){
        char temp=str[st];
        str[st]=str[end];
        str[end]=temp;
        st++;   end--;
    }
    return str;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    s=reverse(s,0,(s.length()-1));
	    cout<<s<<endl;
	}
	
	return 0;
}