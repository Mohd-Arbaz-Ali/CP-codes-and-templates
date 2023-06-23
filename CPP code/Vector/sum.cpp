/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<iostream>
#include<set>
#include<iterator>
using namespace std;

int main(){
	set<int>A;
	set<int>C;
	set<int>B;
	int N,M,val;
	cin>>N;
	for(int i=0;i<N&&N<=100;i++){
		cin>>val;
		A.insert(val);
	}
	cin>>M;
	for(int i=0;i<M&&M<=100;i++){
		cin>>val;
		C.insert(val);
	}
	B.insert(*C.begin()-*A.begin());
	B.insert(*C.end()-*A.end());
	set<int>::iterator it1=A.begin();
	set<int>::iterator it2=B.begin();
	set<int>::iterator it3=B.end();
	set<int>::iterator it4;
	for(it4=C.begin();it4!=C.end();it4++){
		val=*it4-*it1;
		if(val>*it2&&val<*it3){
			B.insert(val);
		}
	}

	for(it2=B.begin();it2!=B.end();it2++){
		cout<<*it2<<"  ";
	}

	return 0;
}
