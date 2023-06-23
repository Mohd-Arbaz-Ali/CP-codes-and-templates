#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	int ar[n][m];

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>ar[i][j];
		}
	}

	int st_row=0;
	int end_row=n-1;
	int st_col=0;
	int end_col=m-1;

	while((st_row<=end_row)&&(st_col<=end_col)){

		for(int col=st_row;col<=end_col;col++)
			cout<<ar[st_row][col]<<" ";
		st_row++;

		for(int row=st_row;row<=end_row;row++)
			cout<<ar[row][end_col]<<" ";
		end_col--;

		for(int col=end_col;col>=st_col;col--)
			cout<<ar[end_row][col]<<" ";
		end_row--;

		for(int row=end_row;row>=st_row;row--)
			cout<<ar[row][st_col]<<" ";
		st_col++;
	}

	return 0;
}