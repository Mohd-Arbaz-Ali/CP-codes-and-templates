#include<bits/stdc++.h>
using namespace std;
vector<bool>seive(1e5+1,true);
void seiveOfEratosthenes(){
	seive[0]=seive[1]=false;
    for(int i=2;i*i<100001;i++){
    	if(seive[i]){
    		for(int j=i*i;j<=100001;j+=i){
                seive[j]=false;
    		}
    	}
    }
}
int prime(int n){
	int count=0;
	for(int i=2;i<n;i++)
		if(seive[i]) count++;
	return count;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
    seiveOfEratosthenes();
	while(t--){
		int n;
		cin>>n;
		cout<<prime(n)<<endl;
	}
	return 0;
}