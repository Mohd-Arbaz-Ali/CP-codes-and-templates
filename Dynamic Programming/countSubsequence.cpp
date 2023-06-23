#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
ll m=1e9+7 ;
ll mod(ll a){
    return ((a%m)+m)%m;
}
ll add(ll a,ll b){
    return mod(mod(a)+mod(b));
}
ll mul(ll a,ll b){
    return mod(mod(a)*mod(b));
}
ll power(ll x,ll n){
    if(n==0)
        return 1;
    ll ans=mod(power(x,n/2));
    ans=mul(ans,ans);
    if(n%2)
        ans=mul(ans,x);
    return ans;
}
vector<vector<int>>dp(100001,vector<int>(9,-1));
int solve(int i,int j,string &s,string &org){
    if(i<=s.size()&&j==org.size())
        return 1;
    if(i>=s.size()||j>=org.size())
        return 0;
    if(not(dp[i][j]==-1)) return dp[i][j];
    int count=0;
    if(s[i]==org[j])
        count=add(count,solve(i+1,j+1,s,org));
    count=add(count,solve(i+1,j,s,org));
    return dp[i][j]=count;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    string org="chokudai";
    cout<<solve(0,0,s,org)<<endl;;
 
    return 0;
}