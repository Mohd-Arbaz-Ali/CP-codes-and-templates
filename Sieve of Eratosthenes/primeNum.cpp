#include<bits/stdc++.h>
using namespace std;

void primeNum(int n){
	int sieve[n+1]={0};
	for(int i=2;i<=n;i++){
		if(sieve[i]==0){
			for (int j = i*i; j <= n; j+=i)
			{
				sieve[j]=1;
			}
		}
	}
	for(int i=2;i<=n;i++){
		if(sieve[i]==0)
			cout<<i<<" ";
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	primeNum(n);
	return 0;
}