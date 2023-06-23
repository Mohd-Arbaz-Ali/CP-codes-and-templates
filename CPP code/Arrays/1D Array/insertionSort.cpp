#include<bits/stdc++.h>
using namespace std;

int main(){

	int *ar=new int[5]{45,23 ,43,7,12};

	for(int i=0;i<5;i++){
		cin>>ar[i];
	}

	int temp;
	for(int i=1;i<5;i++){
		temp=ar[i];
		int j=i-1;
		while(j>=0){
			if(temp<ar[j]){
				ar[j+1]=ar[j];
			}
			else{
				break;
			}
			j--;
		}
		ar[j+1]=temp;
	}

	for(int i=0;i<5;i++){
		cout<<ar[i]<<" ";
	}

	return 0;
}