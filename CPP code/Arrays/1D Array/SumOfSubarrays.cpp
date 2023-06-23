#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin>>n;
	int ar[n];

	for(int i=0;i<n;i++)
		cin>>ar[i];

	for(int i=0;i<n;i++){
		int curr=0;
		for(int j=i;j<n;j++){
			curr+=ar[j];
			cout<<curr<<" ";
		}
	}

	return 0;
}