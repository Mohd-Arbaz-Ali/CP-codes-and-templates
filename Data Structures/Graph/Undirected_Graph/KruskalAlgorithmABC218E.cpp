#include<bits/stdc++.h>
#include <cstdint>
//#define int64_t long long 
using namespace std;
class union_find{
    vector<int>par,sz;
public:
	union_find(int n){
		par.resize(n);
		sz.resize(n);
		for(int i=0;i<n;i++){
			par[i]=i; sz[i]=0;
		}
	}
	int find(int x){
		if(par[x]==x) return x;
		return par[x]=find(par[x]);
	}
	void unite(int u,int v){
		int uset=find(u);
		int vset=find(v);
		if(uset==vset) return;
		if(sz[uset]<sz[vset]){
			par[uset]=vset;
			sz[vset]++;
		}else{
			par[vset]=uset;
			sz[uset]++;
		}
	}
	int size(int x){
		return sz[find(x)];
	}
};
int main(){
	int n,m;
	cin>>n>>m;
	vector<pair<int64_t,pair<int64_t,int64_t>>>g;
	int64_t ans=0;
	for(int i=0;i<m;i++){
		int u,v; cin>>u>>v; u--; v--;
		int w; cin>>w;
		g.push_back({w,{u,v}});
	}
	sort(g.begin(),g.end());
	union_find un(n);
	int count=0;
	int i=0;
	for(;count<n-1;i++){
		if(un.find(g[i].second.first)==un.find(g[i].second.second)){
			if(g[i].first>0) ans+=g[i].first;
		}else{
			un.unite(g[i].second.first,g[i].second.second);
			count++;
		}
	}
	for(;i<m;i++){
		if(g[i].first>0) ans+=g[i].first;
	}
	cout<<ans<<endl;
	return 0;
}