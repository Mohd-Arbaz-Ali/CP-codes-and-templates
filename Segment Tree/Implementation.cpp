#include<bits/stdc++.h>
#define int long long
using namespace std;
int arr[100001];
int v[400001];
/*class SegTree{
    public:
    vector<pair<int,int>>v;
    	void bulid(int node,int s,int e){
    		if(s==e){
    			v[node]={INT_MIN,arr[s]};
    			return;
    		}
    		int mid=(s+e)/2;
    		bulid(node*2,s,mid);
    		bulid((node*2)+1,mid+1,e);
    		if(v[2*node].second>v[2*node+1].second){
    		    v[node].second=v[2*node].second;
    		    v[node].first=max(v[2*node].first,v[2*node+1].second);
    		}else{
    		    v[node].second=v[2*node+1].second;
    		    v[node].first=max(v[2*node+1].first,v[2*node].second);
    		}
    	}
    	SegTree(int n){
    	    v.resize(400001);
    		bulid(1,1,n);
    	}
    	pair<int,int> queries(int node,int s,int e,int l,int r){
    		if(r<s || l>e){
    			return {INT_MIN,INT_MIN};
    		}
    		if(l<=s && r>=e){
    			return v[node];
    		}
    		int mid=(s+e)/2;
    		pair<int,int> left=queries(2*node,s,mid,l,r);
    		pair<int,int> right=queries(2*node+1,mid+1,e,l,r);
    		if(left.second>right.second){
    		    return {max(right.second,left.first),left.second};
    		}else{
    		    return {max(right.first,left.second),right.second};
    		}
    	}
};*/
class SegTree{
    public:
        vector<int>v;
    	void bulid(int node,int s,int e){
    		if(s==e){
    			v[node]=arr[s];
    			return;
    		}
    		int mid=(s+e)/2;
    		bulid(node*2,s,mid);
    		bulid((node*2)+1,mid+1,e);
    		v[node]=min(v[node*2],v[(2*node)+1]);
    	}
    	SegTree(int n){
            v.resize(400001);
    		bulid(1,1,n);
    	}
    	int queries(int node,int s,int e,int l,int r){
    		if(r<s || l>e){
    			return 1e18;
    		}
    		if(l<=s && r>=e){
    			return v[node];
    		}
    		int mid=(s+e)/2;
    		int left=queries(2*node,s,mid,l,r);
    		int right=queries(2*node+1,mid+1,e,l,r);
    		return min(left,right);
    	}
    	void update(int node,int s,int e,int qi){
    		if(s==e){
    			v[node]=arr[s];
    			return;
    		}
    		int mid=(s+e)/2;
    		if(qi<=mid)
    		    update(2*node,s,mid,qi);
    		else update(2*node+1,mid+1,e,qi);
    		v[node]=min(v[2*node],v[2*node+1]);
    	}
};
int32_t main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    	cin>>arr[i];
    SegTree s(n);
    int q;
    cin>>q;
    while(q--){
    	int l,r;
    	cin>>l>>r;
    	cout<<s.queries(1,1,n,l+1,r+1)<<endl;
    }
	return 0;
}