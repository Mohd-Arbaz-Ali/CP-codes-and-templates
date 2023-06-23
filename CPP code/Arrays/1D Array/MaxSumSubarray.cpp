#include<bits/stdc++.h>
using namespace std;

/*int main(int argc, char const *argv[])     //Using Cumulative sum array
{
	int n;								
	cin>>n;
	int *ar=new int[n];

	for(int i=0;i<n;i++)
		cin>>ar[i];

	int curSum[n+1];
	curSum[0]=0;

	for(int i=1;i<n+1;i++)
		curSum[i]=curSum[i-1]+ar[i-1];

	int maxSum=INT_MIN;
	for(int i=1;i<n+1;i++){
		int sum=0;
		for(int j=0;j<i;j++){
			sum=curSum[i]-curSum[j];
			maxSum=max(sum,maxSum);
		}
	}

	cout<<maxSum;

	return 0;
}*/

int main(int argc, char const *argv[])		//Using Kadane's algorithm.
{
	int n;								
	cin>>n;
	int *ar=new int[n];

	for(int i=0;i<n;i++)
		cin>>ar[i];

	int curSum=0;
	int maxSum=INT_MIN;
	for(int i=0;i<n;i++){
		curSum+=ar[i];
		if(curSum<0)
			curSum=0;
		maxSum=max(curSum,maxSum);
	}

	cout<<maxSum;

	return 0;
}