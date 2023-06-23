#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *ar=new int[n];

	for(int i=0;i<n;i++)
		cin>>ar[i];

	const int N=1e6 + 1;
	bool check[N]={false};

	for(int i=0;i<n;i++){
		if(ar[i]>0)
			check[ar[i]]=true;
	}

	for(int i=1;i<N;i++){
		if(check[i]==false){
			cout<<i;
			break;
		}
	}

	return 0;
}