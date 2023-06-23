#include<iostream>
using namespace std;

bool isSorted(int ar[],int n){
	if(n==1)
		return true;
	bool res;
	if(ar[0]<=ar[1]){
		res=isSorted(ar+1,n-1);
	}
	else
		return false;
	return res;
}

int main(int argc, char const *argv[])
{
	int ar[]={3,2,3,4,5,6,7};
	cout<<isSorted(ar,7)<<endl;
	return 0;
}