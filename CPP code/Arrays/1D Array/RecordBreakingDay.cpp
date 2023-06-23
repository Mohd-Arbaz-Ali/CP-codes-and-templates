#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin>>n;
	int *ar=new int[n+1];
	ar[n]=-1;

	for(int i=0;i<n;i++)
		cin>>ar[i];

	if(n==1){
		cout<<n;
		return 0;
	}

	int mx=-1,count=0;
	for(int i=0;i<n;i++){
		if((ar[i]>ar[i+1])&&(ar[i]>mx)){
			mx=ar[i];
			count++;
		}
	}
	cout<<count;

	return 0;
}