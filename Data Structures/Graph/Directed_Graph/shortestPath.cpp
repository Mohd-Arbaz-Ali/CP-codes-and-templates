#include<bits/stdc++.h>
#define int int64_t
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
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
void shortesPath(vector<int>g[],vector<int>&dis){
    queue<int>q;
    q.push(1);
    while(not q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:g[u]){
            if(v==-1) continue;
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
}
void solve(){
    int n,m; cin>>n>>m;
    vector<int>g[n+1];
    vector<pair<int,int>>p;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        p.push_back({u,v});
        g[u].push_back(v);
    }
    vector<int>dis(n+1,INT_MAX);
    dis[1]=0;
    shortesPath(g,dis);
    if(dis[n]==INT_MAX){
        for(int i=0;i<m;i++){
            cout<<-1<<endl;
        }
    }
    for(int i=0;i<m;i++){
        pair<int,int>pi=p[i];
        int u=pi.first; 
        int v=pi.second;
        for(int j=0;j<g[u].size();j++){
            if(g[u][j]==v){
                g[u][j]=-1;
                break;
            }
        }
        dis.clear();
        dis.resize(n+1,INT_MAX);
        dis[1]=0;
        shortesPath(g,dis);
        if(dis[n]==INT_MAX) cout<<-1<<endl;
        else cout<<dis[n]<<endl;
        for(int j=0;j<g[u].size();j++){
            if(g[u][j]==-1){
                g[u][j]=v; break;
            }
        }
    }
}
int32_t main(){
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}