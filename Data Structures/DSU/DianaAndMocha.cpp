#include<bits/stdc++.h>
using namespace std;
class union_find{
public:
	vector<int>par;
    vector<int>sz;
	union_find(int n){
		par.resize(n+1);
		sz.resize(n+1);
		for(int i=0;i<=n;i++){
			par[i]=i;
			sz[i]=1;
		}
	}
	int find(int n){
        if(par[n]==n)
        	return n;
        return par[n]=find(par[n]);
	}
	void unite(int u,int v){
		int up=find(u);
		int vp=find(v);
		if(up==vp) return;
		if(sz[up]<sz[vp]){
			par[up]=vp;
			sz[vp]++;
		}else{
			par[vp]=up;
			sz[up]++;
		}
	}
	int size(int x){
		return sz[find(x)];
	}
};
int main(){
    int n,m1,m2;
    cin>>n>>m1>>m2;
    union_find diana(n);
    union_find mocha(n);
    vector<pair<int,int>>res;
    for(int i=1;i<=m1;i++){
    	int u,v;
    	cin>>u>>v;
    	mocha.unite(u,v);
    }
    for(int i=1;i<=m2;i++){
    	int u,v;
    	cin>>u>>v;
    	diana.unite(u,v);
    }
    for(int i=2;i<=n;i++){
        if(not(diana.find(i)==diana.find(1)) && not(mocha.find(i)==mocha.find(1))){
            res.push_back({1,i});
            diana.unite(1,i);
            mocha.unite(1,i);
        }
    }
    int l=1,r=1;
    while(l<=n && r<=n){
        while(l<=n && (diana.find(l)==diana.find(1))) l++;
        while(r<=n && (mocha.find(r)==mocha.find(1))) r++;
        if(l>n || r>n) break;
        diana.unite(l,r);
        mocha.unite(l,r);
        res.push_back({l,r});
    }
    cout<<res.size()<<endl;
    for(auto it:res){
    	cout<<it.first<<" "<<it.second<<endl;;
    }
	return 0;
}