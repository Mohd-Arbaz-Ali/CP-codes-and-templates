#include<bits/stdc++.h>
#define int long long
int mod=1e9+7;
using namespace std;
int32_t main(){
	int V,E;
	cin>>V>>E;
	vector<int>g[V+1];
	for(int i=1;i<=E;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int>dis(V+1,INT_MAX);
	vector<int>cnt(V+1);
	cnt[1]=1;
	dis[1]=0;
	queue<int>q;
	q.push(1);
	while(not q.empty()){
		int u=q.front();
		q.pop();
		for(auto i : g[u]){
			if(dis[i]==INT_MAX){
				dis[i]=dis[u]+1;
				cnt[i]=cnt[u];
				q.push(i);
			}else if(dis[i]==dis[u]+1){
				cnt[i]=(cnt[i]+cnt[u])%mod;
			}
		}
	}
	cout<<cnt[V]<<endl;
	return 0;
}