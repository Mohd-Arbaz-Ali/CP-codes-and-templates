#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    map<int,vector<int>>m;
    set<int>ls;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        m[l].push_back(r);
        ls.insert(l);
    }
    priority_queue<int, vector<int>, greater<int>>pq;
    int i=*ls.begin();
    bool ans=true;
    while(i<=1000000000){
        for(auto x:m[i])
            pq.push(x);
        pq.pop();
        if(pq.empty()){
            auto it = ls.upper_bound(i);
            if(it==ls.end()) break;
            else i=*it;
        }else{
            if(pq.top()<=i){
                ans=false;
                break;
            }
            i++;
        }
    }
    if(pq.empty() && ans)
        cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}
int32_t main(){
	int t;
    cin>>t;
    while(t--){
        solve();
    }
	return 0;
}