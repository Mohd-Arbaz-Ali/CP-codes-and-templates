#include<bits/stdc++.h>
using namespace std;

int main(){
	/*#ifndef ONLINE_JUDGE

	freopen("input1.txt","r",stdin);

	freopen("output1.txt","w",stdout);

	#endif*/

	int T,N,temp,count=0,j=1,x=0;
	int *ar;

	cin>>T;
	if(T<1&&T>1000)
		return 0;
	while(T){
		cin>>N;
		if(N<2&&N>50000)
				return 0;
		ar=new int[N];

		for(int i=0;i<N;i++){
			cin>>ar[i];
		}

		if(N==2&&ar[1]<ar[0]){
			cout<<"NO";
			return 0;
		}

		while(1){
			x=0;
			for(int i=0;i<N-j;i++){
				if(ar[i]>ar[i+1]){
					temp=ar[i];
					ar[i]=ar[i+1];
					ar[i+1]=ar[i];
					count++;
				}
				else
					x++;
			}
			j++;
			if(x==N-2&&j==3){
				break;
			}
			else if(j==N-1){
				break;
			}
		}

		if(count<N*(N-1)/2){
			cout<<"YES";
		}
		else
			cout<<"NO";

		T--;
	}

	return 0;
}