#include<bits/stdc++.h>
#define int long long
using namespace std;
void mst(vector<pair<int,int>>g[],int n,int m,int tot){
	vector<int>weight(n+1,INT_MAX);
	vector<int>par(n+1,-1);
	vector<bool>vis(n+1);
	weight[1]=0; 
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({0,1});
	while(not pq.empty()){
		pair<int,int> x=pq.top();
		int u=x.second;
		pq.pop();
		vis[u]=true;
		for(auto y:g[u]){
			int v=y.first;
			int wt=y.second;
			if(not vis[v] && wt<weight[v]){
				weight[v]=wt;
				pq.push({wt,v});
				par[v]=u;
			}
		}
	}
	int mn=0;
	for(int i=2;i<=n;i++){
	    if(weight[i]>0)
		    mn+=weight[i];
	}
	cout<<tot-mn<<endl;
}
int32_t main(){
	int n; cin>>n;
	int m; cin>>m;
	vector<pair<int,int>>g[n+1];
	int tot=0;
	for(int i=1;i<=m;i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		if(wt>0)
		    tot+=wt;
		if(u==v) continue;
		g[u].push_back({v,wt});
		g[v].push_back({u,wt});
	}
	if(tot==0) cout<<0<<endl;
	else
	    mst(g,n,m,tot);
	return 0;
}