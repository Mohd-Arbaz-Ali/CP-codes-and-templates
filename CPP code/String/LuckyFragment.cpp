#include<bits/stdc++.h>
#include<string>
using namespace std;

int luckyFragment(string str){
    int count=0;
    int ans=0;
    for(int i=0;str[i]!='\0';i++){
        if((i+4)<str.size()){
            if(str.substr(i,4)=="KICK"){
                //cout<<str.substr(i,4)<<" ";
                count++;    
                //cout<<count<<" ";
            }
            else if(str.substr(i,5)=="START"){
                //cout<<str.substr(i,5)<<" ";
                ans+=count;     
                //cout<<ans<<" ";
            }
        }
    }
    
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int ans=luckyFragment(str);
        cout<<ans<<endl;
    }
}