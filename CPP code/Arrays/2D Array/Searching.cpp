#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int m,n,key;
	cin>>m>>n>>key;
	int ar[m][n];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>ar[i][j];

	int row=m-1;
	int col=0;
	bool ans=false;
	while(row>=0&&col<n){
		if(ar[row][col]==key){
			ans=true;
			break;
		}
		else if(ar[row][col]>key)
			row--;
		else
			col++;
	}
	ans?cout<<true:cout<<false;

	return 0;
}