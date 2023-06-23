#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>&input,int n){
	int k,flag=0;
	for(int i=n-1;i>0;i--){
		if(input[i]>input[i-1]){
			k=i-1;
			flag=1;
			break;
		}
	}
	if(flag==0){
		reverse(input.begin(),input.end());
	}else{
		int l;
		for(l=n-1;l>k;l--)
			if(input[l]>input[k])
				break;
		swap(input[k],input[l]);
		reverse(input.begin()+k+1,input.end());
	}
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		vector<int>input;
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			int num;
			cin>>num;
			input.push_back(num);
		}
        nextPermutation(input,n);
        for(int i=0;i<n;i++)
        	cout<<input[i]<<" ";
        cout<<endl;
	}
	
	return 0;
}