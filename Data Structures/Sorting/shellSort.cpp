#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int arr[]={12, 34, 54, 2, 3};
	int n=sizeof(arr)/sizeof(arr[0]);
	for(int gap=n/2;gap>0;gap/=2){
		for(int i=gap;i<n;i++){
			int temp=arr[i];
			int j;
			for(j=i; j>=gap && arr[j-gap]>arr[j];j-=gap){
				arr[j]=arr[j-gap];
			}
			arr[j]=temp;
		}
	}
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}