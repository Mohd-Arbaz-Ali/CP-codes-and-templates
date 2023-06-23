#include<iostream>
#define int long long
using namespace std;
const int32_t mod=1e9+7;
int modExp(int x,int y){
	if(y==0) return 1;
	int ans=modExp(x,y/2);
	if(y%2){
		return (((ans*ans)%mod)*x)%mod;
	}
	return (ans*ans)%mod;
}
int32_t main(){
	int n;
	cin>>n;
	int sum=0;
	for(int i=1,j;j<=n;i=j){
		int q=n/i;
		j=(n/q)+1;
		int onetoi=((((i%mod)*((i-1)%mod))%mod)*modExp(2,mod-2))%mod;
		int onetoj=((((j%mod)*((j-1)%mod))%mod)*modExp(2,mod-2))%mod;
		int res=(((onetoj-onetoi+mod)%mod)*q)%mod;
		sum=(sum+res)%mod;
	}
	cout<<sum<<endl;
	return 0;
}