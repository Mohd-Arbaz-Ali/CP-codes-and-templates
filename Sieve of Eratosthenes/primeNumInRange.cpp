#include<bits/stdc++.h>
using namespace std;

void primeNum(int n,int m){
	int sieve[m+1]={0};
	for(int i=2;i<=m;i++){
		if(sieve[i]==0){
			for (int j = i*i; j <= m; j+=i)
			{
				sieve[j]=1;
			}
		}
	}
	for(int i=n;i<=m;i++){
		if(sieve[i]==0)
			cout<<i<<" ";
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int n,m;
	cout<<"Enter the range of numbers : ";
	cin>>n>>m;
	primeNum(n,m);
	return 0;
}