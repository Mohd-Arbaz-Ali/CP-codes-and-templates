#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include<stdio.h>
using namespace std;


int main() {
    int q,type,y;
    string x;
    map<string,int>m;  
    cin>>q;
    while(q>=1&&q<=100000){
        cin>>type;
        if(type==1)
        {
            cin>>x;
            cin>>y;
            map<string,int>::iterator itr=m.find(x);
            if(m.find(x)!=m.end()){
                itr->second+=y;
            }
            else
                m.insert(make_pair(x,y));
        }
        else if(type==2){
            cin>>x;
            m.erase(x);
        }
        else if(type==3){
            cin>>x;
            if(m.find(x)!=m.end()){
                cout<<m[x]<<endl;
            }
            else
                cout<<"0"<<endl;
        }
        q--;
    } 
    return 0;
}



