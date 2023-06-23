#include<bits/stdc++.h>
#define int int64_t
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
//template <class T> using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update >; // find_by_order, order_of_key
#define vvi vector<vector<int>>
#define vi vector<int>
int MOD=1e9+7 ;
int MAXN=1e5+1;
int mod(int a){return ((a%MOD)+MOD)%MOD;}
int add(int x,int y){return mod(mod(x)+mod(y));}
int mul(int x,int y){return mod(mod(x)*mod(y));}
int binpow(int a, int b) {a %= MOD;int res = 1;while (b > 0) {
if (b & 1)res = res * a % MOD;a = a * a % MOD;b >>= 1;}return res;}
int fact(int n){int num=1;for(int i=1;i<=n;i++){num=mul(num,i);mod(num);}return num;}
int ncr(int n,int r){int fn=fact(n);int rn=mod(fact(r)*fact(n-r));return mod(fn*binpow(rn,MOD-2));}
/*------------------------------------------------------------------------------------------------*/

void solve(){
    
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