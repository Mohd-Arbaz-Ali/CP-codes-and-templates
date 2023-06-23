#include<bits/stdc++.h>
using namespace std;

bool PairTargetSum(int *ar,int n,int key){
	sort(&ar[0],&ar[n-1]);
	int low=0;
	int high=n-1;
	while(low<=high){
		if(ar[low]+ar[high]==key){
			cout<<low<<" "<<high;
			return true;
		}
		else if(ar[low]+ar[high]<key)
			low++;
		else
			high--;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int n,k;
	cin>>n>>k;
	int *ar=new int[n];

	for(int i=0;i<n;i++)
		cin>>ar[i];

	if(PairTargetSum(ar,n,k)==false)
		cout<<-1;

	return 0;
}