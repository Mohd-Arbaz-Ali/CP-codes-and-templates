#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){
	int *arr;
	//arr=new int[5];
	arr=(int*)malloc(sizeof(int)*5);
	for(int i=0;i<5;i++){
		cin>>arr[i];
	}
	for(int i=0;i<5;i++){
		cout<<arr[i]<<endl;
	}
	return 0;
}