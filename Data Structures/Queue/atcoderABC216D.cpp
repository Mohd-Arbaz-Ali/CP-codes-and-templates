#include<bits/stdc++.h>
#define int long long
using namespace std;
int MOD=998244353;
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
int power(int x,int y){
    if(y==0) return 1;
    int ans=power(x,y/2);
    ans=mul(ans,ans);
    if(y%2==1){
        ans=mul(ans,x);
    }
    return ans;
}
void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>cyl(m);
	queue<pair<int,int>>q;
	for(int i=0;i<m;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int ki;
			cin>>ki;
			cyl[i].push_back(ki);
		}
		q.push({cyl[i].back(),i});
	}
    set<int>s;
    vector<int>idx(2e5+1);
    while(not q.empty()){
    	auto [x,y]=q.front();
    	q.pop();
    	if(s.find(x)==s.end()){
    		s.insert(x);
    		idx[x]=y;
    	}else{
    		s.erase(x);
    		cyl[y].pop_back();
    		cyl[idx[x]].pop_back();
    		if(not cyl[y].empty()){
    			q.push({cyl[y].back(),y});
    		}
    		if(not cyl[idx[x]].empty()){
    			q.push({cyl[idx[x]].back(),idx[x]});
    		}
    	}
    }
    if(s.empty()){
    	cout<<"Yes\n";
    }else cout<<"No\n";
}
int32_t main(){
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}