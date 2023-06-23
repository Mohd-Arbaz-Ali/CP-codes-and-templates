#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

int main() {
	int T,n,num,temp=0,y=0;
	cin>>T;
	while(T>=1&&T<=100){
	    cin>>n;
	    vector<int>v{1};
	    while(n>=1&&n<=100){
    	    for(int i=0;i<v.size();i++){
    	        num=n*v[i]+temp;
    	        v[i]=num%10;
    	        temp=num/10;
    	    }
    	    while(temp!=0){
    	        v.push_back(temp%10);
    	        temp=temp/10;
    	    }
    	    n--;
	    }
	    for(auto itr=v.end()-1;itr!=v.begin()-1;itr--){
	        cout<<*itr;
	    }
	    cout<<endl;
	    T--;
	}
	return 0;
}
