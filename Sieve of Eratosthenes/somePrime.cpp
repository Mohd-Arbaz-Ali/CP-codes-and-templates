#include <iostream>
using namespace std;

int main() {
	long prime[100000001]={0};
	for(long i=2;i<=100000000;i++){
		if(i*i>100000000)	break;
		if(prime[i]==0){
			for(long j=i*i;j<=100000000;j+=i){
				prime[j]=1;
			}
		}
	}
	int count=0;
	for(long i=2;i<=100000000;i++){
		if(prime[i]==0){
			count++;
		}
		if(count%100==1){
			cout<<i<<endl;
		}
	}
	
	return 0;
}