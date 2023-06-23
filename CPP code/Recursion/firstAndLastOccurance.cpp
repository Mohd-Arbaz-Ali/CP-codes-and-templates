#include<bits/stdc++.h>
using namespace std;

int firstOccurance(int ar[],int n,int i,int key){
	if(i>n)
		return -1;
	if(ar[0]==key)
		return i;
	int res=firstOccurance(ar+1,n,i+1,key);
	return res;
}

int lastOccurance(int ar[],int n,int i,int key){
	if(i>n)
		return -1;
	int res=lastOccurance(ar+1,n,i+1,key);
	if((ar[0]==key) && (res==-1))
		return i;
	return res;
}

int main(int argc, char const *argv[])
{
	int ar[]={4,2,3,5,4,7};
	cout<<firstOccurance(ar,6,1,4)<<endl;
	cout<<lastOccurance(ar,6,1,4)<<endl;
	return 0;
}