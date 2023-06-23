#include <bits/stdc++.h>
#define int long long
using namespace std;
int MOD;
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
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>dp(n+1);
    int sum=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=sum;
        for(int j=1;j*j<=i;j++){
            dp[i]+=(dp[j]*(i/j-i/(j+1)))%m;
            dp[i]%=m;
            if((not (j==i/j)) && j>1){
                dp[i]+=dp[i/j];
                dp[i]%=m;
            }
        }
        sum+=dp[i];
        sum%=m;
    }
    cout<<dp[n]<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}