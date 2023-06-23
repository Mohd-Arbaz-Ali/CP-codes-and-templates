#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *ar=new int[n];
	int Sum=0;

	for(int i=0;i<n;i++){
		cin>>ar[i];
		Sum+=ar[i];
	}

	for (int i = 0; i < n; ++i)
	{
		ar[i]=-ar[i];
	}

	int curSum=0;
	int maxSum=INT_MIN;
	for(int i=0;i<n;i++){
		curSum+=ar[i];
		if(curSum<0)
			curSum=0;
		maxSum=max(curSum,maxSum);
	}

	cout<<Sum<<" "<<Sum+maxSum;

	return 0;
}