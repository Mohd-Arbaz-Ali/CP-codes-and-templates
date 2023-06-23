#include<bits/stdc++.h>
using namespace std;

int main(){
	int max=1000001;
	int primeFact[max]={0};
	for(int i=2;i<max;i++){
		primeFact[i]=i;
	}
	for(int i=2;i<max;i++){
		if(primeFact[i]==0){
			for(int j=i*i;j<max;j+=i){
				if(primeFact[j]==j){
					primeFact[j]=i;
				}
			}
		}
	}
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int count=0;
		for(int i=n;i<max;i+=n){
			if(primeFact[i]==n)
				count++;
		}
		cout<<count<<endl;
	}

	return 0;
}