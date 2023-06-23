#include<bits/stdc++.h>
#define int long long
using namespace std;
int MOD=998244353 ;
int MAXN=1e5+1;
int mod(int a){
    return ((a%MOD)+MOD)%MOD;
}
int add(int x,int y){
    return mod(mod(x)+mod(y));
}
int mul(int x,int y){
    return mod(mod(x)*mod(y));
}
int power(int x,int y){
    if(y==0) return 1;
    int ans=power(x,y/2);
    ans=mul(ans,ans);
    if(y%2==1){
        ans=mul(ans,x);
    }
    return ans;
}
std::vector<int> sz(MAXN);
vector<int>ones(MAXN);
void preCompute(){
    ones[0]=0;
    ones[1]=1;
    sz[0]=1;
    sz[1]=1;
    for(int i=2;i<MAXN;i++){
        ones[i]=add(ones[i-1],ones[i-2]);
        sz[i]=(sz[i-1]%(MOD-1))+(sz[i-2]%(MOD-1));
    }
}
void solve(){
    int n;
    cin>>n;
    int res=mul(ones[n],power(2,(sz[n]-1)%(MOD-1)));
    cout<<res<<endl;
}
int32_t main() {
	int t;
	cin>>t;
	preCompute();
	while(t--){
	    solve();
	}
	return 0;
}
