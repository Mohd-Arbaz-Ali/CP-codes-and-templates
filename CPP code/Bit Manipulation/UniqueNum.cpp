#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

void Solution(int arr[],int n){
	int xor_sum=0;
	for(int i=0;i<n;i++){
		xor_sum^=arr[i];
	}
	//cout<<xor_sum<<endl;
	int set_bit;
	for(int i=0;i<64;i++){
		if((xor_sum & (1<<i))!=0)
		{
			set_bit=(1<<i);
			break;
		}
	}
	//cout<<set_bit<<endl;
	int num1=0,num2=0;
	for(int i=0;i<n;i++){
		if((set_bit&arr[i])==set_bit)		num1^=arr[i];
		else	num2^=arr[i];
	}
	cout<<"Unique numbers in array are "<<num1<<" and "<<num2<<endl;
}

int main(){

	int arr[]={4,2,6,7,4,5,6,2};
	Solution(arr,(sizeof(arr)/sizeof(arr[0])));

	return 0;
}