#include<bits/stdc++.h>
#define ll long long int
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T> using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update >; // find_by_order, order_of_key
const int MOD=998244353 ;
const int MAXN=300005;
ll mod(ll a){return ((a%MOD)+MOD)%MOD;}
ll add(ll x,ll y){return mod(mod(x)+mod(y));}
ll mul(ll x,ll y){return mod(mod(x)*mod(y));}
ll binpow(ll a, ll b) {a %= MOD;ll res = 1ll;while (b > 0ll) {
if (b & 1ll)res = res * a % MOD;a = a * a % MOD;b >>= 1ll;}return res;}
ll fact(ll n){ll num=1ll;for(ll i=1ll;i<=n;i++){num=mul(num,i);mod(num);}return num;}
ll ncr(ll n,ll r){ll fn=fact(n);ll rn=mod(fact(r)*fact(n-r));return mod(fn*binpow(rn,MOD-2));}
ll inv(ll a){return binpow(a,MOD-2);}
/*------------------------------------------------------------------------------------------------*/
int bit[MAXN];
int get(int i){
    int ans=0;
    while(i){
        ans+=bit[i];
        ans%=MOD;
        i-=i&(-i);
    }
    return ans;
}
void update(int i,int n,int val){
    while(i<=n){
        bit[i]+=val;
        bit[i]%=MOD;
        i+=i&(-i);
    }
}
void solve(){
    int n;
    cin>>n;               
    vector<pair<int,int>>arr;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        arr.push_back({x,i+1});
    }
    sort(arr.begin(),arr.end());
    int ans=0;
    for(int i=n-1;i>=0;i--){
        int idx=arr[i].second;
        int x=(get(n)-get(idx)+MOD)%MOD;
        update(idx,n,binpow(2,idx));
        ans+=mul(x,inv(binpow(2,idx+1)));
        ans%=MOD;
    }
    cout<<ans<<endl;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}