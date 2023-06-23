#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *a=new int[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	if(n==1){
		cout<<a[0];
		return 0;
	}

	int mx=a[0];
	for(int i=1;i<n;i++){
		if(a[i]>mx){
			mx=a[i];
		}
		a[i]=mx;
	}

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";

	return 0;
}