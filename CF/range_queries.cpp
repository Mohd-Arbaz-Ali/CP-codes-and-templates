#include<bits/stdc++.h>
#define int long long int
#define ll long long int
#define pb push_back
#define all(a) a.begin(), a.end()
#define ss second
#define ff first
using namespace std;
void fastIO(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
void file(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);//read
    freopen("output.txt","w",stdout);//write
    #endif
}

void execute_test(){
	int n;
	cin>>n;
	int node=1;
	vector<int>mxSum(2),mnSum(2),curMax(2),curMin(2);
	curMax[1]=mxSum[1]=1;
	for(int i=0;i<n;i++){
		char c;
		cin>>c;
		if(c=='+'){
			int u,k;
			cin>>u>>k;
			mxSum.pb(max(0LL,mxSum[u]+k));
			mnSum.pb(min(0LL,mnSum[u]+k));
			curMax.pb(max(curMax[u],mxSum.back()));
			curMin.pb(min(curMin[u],mnSum.back()));
		}else{
			int u,v,k;
			cin>>u>>v>>k;
			if(curMax[v]>=k&&curMin[v]<=k){
				cout<<"YES\n";
			}else cout<<"NO\n";
		}
	}
	
}

signed main(){
	fastIO();
	file();
	int t=1;
	cin>>t;
	for(int i=0;i<t;i++){
        //cout<<"Case #"<<i+1<<": ";
        execute_test();
    }
	return 0;
}