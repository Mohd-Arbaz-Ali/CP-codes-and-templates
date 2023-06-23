#include<iostream>

using namespace std;

int main() {
	int T,N,K,L;
	cin>>T;
	while(T>=1&&T<=30){
	    cin>>N>>K>>L;
	    if(N<=10000&&N>=1&&K>=1&&K<=10000&&L>=1&&L<=10000){
	        if(K*L>=N&&K!=1){
	            L=1;
	            for(int i=1;i<=N;i++){
	               if(i<=K){
	                   cout<<i<<" ";
	               }
	               else{
	                  cout<<i-(K*L)<<" ";
	               }
	            }
	        }
	        else
	            cout<<"-1";
	    }
	    cout<<endl;
	    T--;
	}
	return 0;
}
