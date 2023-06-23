#include<bits/stdc++.h>
using namespace std;

int getMax(int *arr,int n){
	int res=INT_MIN;
	for(int i=0;i<n;i++)
		res=max(arr[i],res);
	return res;
}

void countSort(int *arr,int n,int exp){
	int count[10]={0};
	int output[n];
	for(int i=0;i<n;i++)
		count[(arr[i]/exp)%10]++;
	for(int i=1;i<10;i++)
		count[i]+=count[i-1];
	for(int i=n-1;i>=0;i--){
		output[count[(arr[i]/exp)%10]-1]=arr[i];
		count[(arr[i]/exp)%10]--;
	}
	for(int i=0;i<n;i++)
		arr[i]=output[i];
}

void radixSort(int *arr,int n){
	int m=getMax(arr,n);
	for(int i=1;m/i>0;i*=10)
		countSort(arr,n,i);
}

int main()
{
	//int arr[]={170, 45, 75, 90, 802, 24, 2, 66};
	int arr[]={10,15,1,60,5,100,25,50};
	int n=sizeof(arr)/sizeof(arr[0]);
	radixSort(arr,n);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}