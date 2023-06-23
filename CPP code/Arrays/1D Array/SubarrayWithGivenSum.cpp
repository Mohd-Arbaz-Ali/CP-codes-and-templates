#include<bits/stdc++.h>
using namespace std;

int main(){

	int n,S;
	cin>>n>>S;
	int *ar=new int[n];

	for(int i=0;i<n;i++)
		cin>>n;

	int curSum=0;
	int st=0,en=0;
	while(en<n&&curSum!=S){
		if(curSum+ar[en]==S){
			curSum+=ar[en];
			break;
		}
		else if(curSum+ar[en]<S){
			curSum+=ar[en];
			cout<<"In "<<curSum<<endl;
			en++;
		}
		else if(curSum+ar[en]>S){
			curSum-=ar[st];
			cout<<"YO "<<curSum<<endl;
			st++;
		}
	}
	if(curSum==S)
		cout<<st<<" "<<en;
	else cout<<-1;

	return 0;
}