#include <iostream>
#include<iomanip>
using namespace std;

int main() {
	int T,n,sum,remainder=0;
	cin>>T;
	while(T>=1&&T<=1000){
	    cin>>n;
	    sum=n%10;
	    while(n>=1&&n<=100000){
	        remainder=n%10;
	        n=n/10;
	    }
	    sum+=remainder;
	    cout<<sum<<endl;
	    T--;
	}
	return 0;
}
