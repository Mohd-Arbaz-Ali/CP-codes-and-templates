#include<bits/stdc++.h>
#define int long long
using namespace std;

class union_find
{
	vector<int>par;
	vector<int>sz;
public:
	union_find(int n){
        par.resize(n+1);
        sz.resize(n+1);
        for(int i=0;i<=n;i++){
        	par[i]=i;
        	sz[i]=1;
        }
	}
	int find(int x){
		if(par[x]==x)
			return x;
		return par[x]=find(par[x]);
	}
	void unite(int u,int v){
		int a=find(u);
		int b=find(v);
		if(not (a==b)){
			if(sz[a]<sz[b]){
				par[a]=b;
				sz[b]+=sz[a];
			}else {
				par[b]=a;
				sz[a]+=sz[b];
			}
		}
	}
	int size(int x){
		return sz[find(x)];
	}
};

int32_t main(){
    vector<pair<int,pair<int,int>>>gr;
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
    	int u,v,w;
    	cin>>u>>v>>w;
    	gr.push_back({w,{u,v}});
    }
    sort(gr.begin(),gr.end());
    union_find un(n);
    int sum=0;
    for(auto i:gr){
    	sum+=(i.first*(un.size(i.second.first)*un.size(i.second.second)));
    	un.unite(i.second.first,i.second.second);
    }
    //un.print();
    cout<<sum<<endl;
	return 0;
}

