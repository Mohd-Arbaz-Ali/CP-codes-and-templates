#include<bits/stdc++.h>
#define ll long long
#define lld long double
#define ff first
#define ss second
#define pb push_back
#define all(a) a.begin(), a.end()
#define forn(i, n) for (int i = 1; i <= int(n); i++)
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update >; // find_by_order, order_of_key
const int32_t MOD=998244353;
const int MAXN=1e7;
void myerase(pbds<ll> &t, int v){
    int rank = t.order_of_key(v);//Number of elements that are less than v in t
    auto it = t.find_by_order(rank); //Iterator that points to the (rank+1)th element in t
    t.erase(it);
}
ll mod(ll a){return ((a%MOD)+MOD)%MOD;}
ll add(ll x,ll y){return mod(mod(x)+mod(y));}
ll mul(ll x,ll y){return mod(mod(x)*mod(y));}
ll binpow(ll a, ll b,ll m) {ll res = 1;while (b > 0) {
if (b & 1)res = res * a % m;a = a * a % m;b >>= 1;}return res;}
ll fact(ll n){ll num=1;for(ll i=1;i<=n;i++){num=mul(num,i);mod(num);}return num;}
ll ncr(ll n,ll r){ll fn=fact(n);ll rn=mod(fact(r)*fact(n-r));return mod(fn*binpow(rn,MOD-2,MOD));}
ll inv(ll a){return binpow(a,MOD-2,MOD);}
bool comp(vector<ll>v1,vector<ll>v2){
    if(v1[1]<v2[1])
        return true;
    return false;
}
//int dx[]={0,1,0,-1};
//int dy[]={1,0,-1,0};
bool is_val(int i,int j,int n,int m){
    return (i>=0&&i<n&&j>=0&&j<m);
}
/*------------------------------------------------------------------------------------------------*/
int dp[200001][19];
vector<int>g[200001];
int timer=0;
int tin[200001];
int tout[200001];
void dfs(int u,int par){
    tin[u]=timer++;
    dp[u][0]=par;
    for(int i=1;i<=18;i++){
        dp[u][i]=dp[dp[u][i-1]][i-1];
    }
    for(auto &v:g[u]){
        if(not(v==par)){
            dfs(v,u);
        }
    }
    tout[u]=timer++;
}
bool is_ancestor(int u,int v){
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
int lca(int u,int v){
    if(is_ancestor(u,v))
        return u;
    if(is_ancestor(v,u))
        return v;
    for(int i=18;i>=0;i--){
        if(not is_ancestor(dp[u][i],v)){
            u=dp[u][i];
        }
    }
    return dp[u][0];
}
void Execute_Test(){
    int n,q;
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        int u;
        cin>>u;
        g[u].pb(i);
    }
    dfs(1,1);
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<lca(u,v)<<endl;
    }
}
int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);//read
    freopen("output.txt","w",stdout);//write
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    //cin>>T;
    while(T--){
        Execute_Test();
    }
    return 0;
}