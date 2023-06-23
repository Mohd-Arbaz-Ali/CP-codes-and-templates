#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

bool func(int x,int y){

	return x>y; 
}

int main()
{
	vector<int> v;
	v.push_back(15);
	v.push_back(5);
	v.push_back(19);
	v.push_back(11);
	v.push_back(9);

	sort(v.begin(),v.end());
	for(int i=0;i<5;i++){
		cout<<v[i]<<" ";
	}
	bool present= binary_search(v.begin(),v.end(),19);
	cout<<endl<<present<<endl;
	present= binary_search(v.begin(),v.end(),10);
	cout<<present<<endl;
	v.push_back(100);
	v.push_back(100);
	v.push_back(100);
	v.push_back(100);
	v.push_back(123);
	vector<int>::iterator it=lower_bound(v.begin(),v.end(),100);
	vector<int>::iterator it1=upper_bound(v.begin(),v.end(),100);

	cout<<*it<<" "<<*it1<<endl;
	cout<<it1-it<<endl;
	cout<<it-v.begin()<<endl;

	sort(v.begin(),v.end(),func);
	vector<int>::iterator it2;
	for(it2=v.begin();it2!=v.end();it2++){
		cout<<*it2<<" ";
	}
	cout<<endl<<*it<<endl;
	advance(it,3);
	cout<<*it<<endl;
	/*vector<int>::iterator itr=prev(it,4);
	cout<<*itr<<endl;
	vector<int>::iterator itr1=next(it,2);
	cout<<*itr1<<endl;*/

	return 0;
}