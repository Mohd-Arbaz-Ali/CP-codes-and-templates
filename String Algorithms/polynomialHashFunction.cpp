#include<bits/stdc++.h>
#define ll long long int
const int mod=1e9+7;
using namespace std;
ll binpow(ll a, ll b,ll m) {
	a %= m;ll res = 1;
	while (b > 0) {
        if (b & 1)
        	res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int hashPrefix[100001]={0};
ll stringHash(string s){
	ll val=0;
	ll p=31;
	ll pw=1;
	for(int i=0;i<s.size();i++){
		val+=((s[i]-'a'+1)*pw)%mod;
		val%=mod;
		pw=(pw*p)%mod;
		hashPrefix[i+1]=val;
	}
	return val;
}
int main(){
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		stringHash(s);
		int sub_hash=(((hashPrefix[5]-hashPrefix[2])+mod)%mod)*binpow(binpow(31,2,mod),mod-2,mod);
		sub_hash=(sub_hash+mod)%mod;
		cout<<sub_hash<<endl;
	}
	return 0;
}

1*p^0+2*p^1+3*p^2