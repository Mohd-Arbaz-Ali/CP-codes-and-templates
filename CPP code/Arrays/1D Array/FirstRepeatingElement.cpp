#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin>>n;
	int ar[n];

	for(int i=0;i<n;i++)
		cin>>ar[i];

	const int N=1e6+1;
	int Idx[N];
	for(int i=0;i<N;i++)
		Idx[i]=-1;
	int minIdx= INT_MAX;

	for(int i=0;i<n;i++){
		if(Idx[ar[i]]!=-1)
			minIdx=min(minIdx,Idx[ar[i]]);
		else
			Idx[ar[i]]=i;
	}

	if(minIdx==INT_MAX)
		cout<<-1;
	else
		cout<<minIdx+1;

	return 0;
	
}