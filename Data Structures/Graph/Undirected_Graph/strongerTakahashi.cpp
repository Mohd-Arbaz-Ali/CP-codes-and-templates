#include<bits/stdc++.h>
using namespace std;

int main(){
	int h,w;
	cin>>h>>w;
	vector<vector<char>>c(h,vector<char>(w));
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>c[i][j];
		}
	}
	int x[]={0,0,-1,1};
	int y[]={-1,1,0,0};
	int allx[]={0,0,-1,-1,-2,-1,-2,-1,-2,-1,0,0,1,1,2,1,2,1,2,1};
	int ally[]={-1,-2,-1,-2,-1,0,0,1,1,2,1,2,1,2,1,0,0,-1,-1,-2};
	set<pair<int,pair<int,int>>>s;
	s.insert({0,{0,0}});
	vector<vector<int>>dis(h,vector<int>(w,INT_MAX));
    dis[0][0]=0;
    while(not s.empty()){
    	pair<int,pair<int,int>>p=*s.begin();
    	int d=p.first;
    	pair<int,int>pre=p.second;
    	s.erase(s.begin());
    	for(int i=0;i<4;i++){
    		int xnew=pre.first+x[i];
    		int ynew=pre.second+y[i];
    		if(xnew<0 || xnew>=h || ynew<0 || ynew>=w) continue;
    		if(c[xnew][ynew]=='.'){
    			if(dis[xnew][ynew]>d){
    				if(not(dis[xnew][ynew]==INT_MAX)){
    					s.erase(s.find({dis[xnew][ynew],{xnew,ynew}}));
    				}
    				dis[xnew][ynew]=d;
    				s.insert({dis[xnew][ynew],{xnew,ynew}});
    			}
    		}else {
                 for(int j=0;j<20;j++){
                 	int xn=pre.first+allx[j];
                 	int yn=pre.second+ally[j];
                 	if(xn<0||xn>=h||yn<0||yn>=w) continue;
                 	if(dis[xn][yn]>d+1){
                 		if(not(dis[xn][yn]==INT_MAX)){
                 			s.erase(s.find({dis[xn][yn],{xn,yn}}));
                 		}
                 		dis[xn][yn]=d+1;
                 		s.insert({dis[xn][yn],{xn,yn}});
                 	}
                 }
    		}
    	}
    }
    cout<<dis[h-1][w-1]<<endl;
	return 0;
}