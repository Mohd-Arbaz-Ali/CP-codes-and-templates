#include<bits/stdc++.h>
using namespace std;

void bucketSort(float *arr,int n){
	vector<float>b[n];
	for(int i=0;i<n;i++){
		int idx=n*arr[i];
		b[idx].push_back(arr[i]);
	}
	for(int i=0;i<n;i++){
		sort(b[i].begin(),b[i].end());
	}
	for(int i=0,idx=0;i<n;i++){
		for(auto it : b[i])
            arr[idx++]=it;
	}
}
int main(int argc, char const *argv[])
{
	float arr[]={.897,0.565,0.656,0.1234,0.665,0.3434};
	int n=sizeof(arr)/sizeof(arr[0]);
	bucketSort(arr,n);
	for(auto i : arr)
		cout<<i<<" ";
	cout<<endl;
	return 0;
}