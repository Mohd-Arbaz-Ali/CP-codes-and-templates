#include<bits/stdc++.h>
using namespace std;

void primeFact(int n){
	int spf[n+1];
	for(int i=2;i<=n;i++)	spf[i] = i;

	for(int i=2;i<=n;i++){

		if(i*i>n)	break;

		if(spf[i]==i){
			for(int j=i*i;j<=n;j+=i){
				if(spf[j]==j){
					spf[j]=i;
				}
			}
		}
	}
	while(n!=1){
		cout<<spf[n]<<" ";
		n=n/spf[n];
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	primeFact(n);
	return 0;
}