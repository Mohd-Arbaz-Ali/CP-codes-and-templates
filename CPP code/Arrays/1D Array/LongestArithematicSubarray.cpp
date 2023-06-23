#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *ar=new int[n];

	for (int i = 0; i < n; ++i)
		cin>>ar[i];

	int dif=ar[1]-ar[0];
	int count=1;
	int res=0;
	for(int i=1;i<n;i++){
		if(ar[i]-ar[i-1]==dif)
			count++;
		else{
			dif=ar[i]-ar[i-1];
			count=2;
		}
		res=max(res,count);
	}

	cout<<res;

	return 0;
}