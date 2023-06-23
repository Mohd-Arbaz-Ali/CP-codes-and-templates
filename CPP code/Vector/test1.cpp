#include<iostream>
#include<string>
using namespace std;

int main() {
	char *s;
	int T,N,K,count=0,temp=0,j=1,i;
	while(T>=1&&T<=1000){
	    cin>>N>>K;
	    s=new char[N];
	    for(i=0;i<N;i++){
	        cin>>s[i];
	    }
	    if(K>N)
	    return 0;
	    
	    for(i=0;i<N;i++){
	        if(s[i]=='1'){
	            count++;
	        }
	        if(i==K*j){
	            temp=K-count;
	            count=0;
	            j++;
	        }
	    }
	    temp+=((i-1)%K)-count;
	    cout<<temp<<endl;
	    T--;
	}
	return 0;
}
