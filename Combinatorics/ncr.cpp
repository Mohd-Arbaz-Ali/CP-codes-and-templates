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
long long binpow(long long a, long long b) {
    a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
int fact(int n){
    int num=1;
    for(int i=1;i<=n;i++){
        num=mul(num,i);
        mod(num);
    }
    return num;
}
int ncr(int n,int r){
    int fn=fact(n);
    int rn=mod(fact(r)*fact(n-r));
    return mod(fn*binpow(rn,MOD-2));
}
void solve(){
    int  n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    if(arr[n-1]==arr[n-2]){
        cout<<fact(n)<<endl;
        return;
    }
    if(arr[n-1]-arr[n-2]>1){
        cout<<0<<endl; return;
    }
    int cnt=0;
    for(int i=n-2;i>=0 && arr[n-1]-arr[i]==1;i--){
         cnt++;
    }
    int ans=ncr(n,cnt+1);
    //cout<<"NCR : "<<ans<<endl;
    int part=mul(fact(cnt),fact(n-(cnt+1)));
    ans=mul(ans,part);
    //cout<<ans<<endl;
    ans=mod(fact(n)-ans);
    cout<<ans<<endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
