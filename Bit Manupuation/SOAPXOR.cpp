#include<iostream>
using namespace std;

int main(){
	int n,res=0;
	cin>>n;
	int *ar=new int[n];
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	for(int i=0;i<=31;i++){
		int countZ=0,countO=0;

		for(int j=0;j<n;j++){
			if(ar[j] & (1<<i))
				countO++;
			else
				countZ++;
		}
		int freq=countZ*countO;
			res+=freq*(1<<i);
	}
	cout<<res<<endl;
}