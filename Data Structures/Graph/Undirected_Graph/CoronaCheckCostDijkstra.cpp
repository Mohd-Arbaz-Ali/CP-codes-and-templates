#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int>>g[2*100001];
int dis[2*100001];
vector<pair<int,int>>slots;
void dijkstra(){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    for(auto i:slots){
        pq.push({i.first,i.second});
        dis[i.second]=i.first;
    }
    while(not pq.empty()){
        pair<int,int>p=pq.top();
        pq.pop();
        for(auto it:g[p.second]){
            if(dis[it.first]>dis[p.second]+it.second){
                dis[it.first]=dis[p.second]+it.second;
                pq.push({dis[it.first],it.first});
            }
        }
    }
}
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    slots.clear();
    for(int i=1;i<=n;i++){
        dis[i]=LONG_MAX;
        g[i].clear();
    }
    for(int i=1;i<=k;i++){
        int u,c;
        cin>>u>>c;
        slots.push_back({c,u});
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dijkstra();
    for(int i=1;i<=n;i++)
        cout<<dis[i]<<" ";
    cout<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}