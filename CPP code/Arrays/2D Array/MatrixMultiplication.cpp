#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int m,n,n2;
	cin>>m>>n;
	int a[m][n];
	cin>>n2;
	int b[n][n2];

	for (int i = 0; i < m; ++i)
	{
		for(int j=0; j<n; j++)
			cin>>a[i][j];
	}

	for (int i = 0; i < n; ++i)
	{
		for(int j=0; j<n2; j++)
			cin>>b[i][j];
	}

	int c[m][n2]={0};
	for(int i=0;i<m;i++)
		for(int j=0;j<n2;j++)
			for(int k=0;k<n;k++){
				c[i][j]+=a[i][k]*b[k][j];
			}

	for(int i=0;i<m;i++){
		for(int j=0;j<n2;j++)
			cout<<c[i][j]<<" ";
		cout<<endl;
	}

	return 0;
}