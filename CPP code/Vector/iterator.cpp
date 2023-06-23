#include<iostream>
#include<vector>
#include<iterator>
#include"stlplus3.h"

using namespace std;

int main(){

	vector<int> v;
	v.push_back(15);
	v.push_back(5);
	v.push_back(19);
	v.push_back(11);
	v.push_back(9);

	vector<int>::iterator it=v.begin();
	vector<int>::iterator it1=v.end();

	vector<int>::iterator itr=next(it,4);
	cout<<*itr<<endl;
	vector<int>::iterator itr1=prev(it1,3);
	cout<<*itr1<<endl;
}