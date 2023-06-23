#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include<stdio.h>
#define get(x) #x
using namespace std;


int main() {
    set<int> S;
    int q,x,y;
    cin>>q;  
    while(q>=1&&q<=100000){
        cin>>y>>x;
        if((y>=1&&x>=1)&&(y<=3&&x>=1000000000)){
            if(y==3){
                if(S.find(x)!=S.end()){
                    printf(get(Yes));
                    cout<<endl;
                }
                else{
                    printf(get(No));
                    cout<<endl;
                }

            }
            else if(y==1){
                S.insert(x);
            }
            else{
                S.erase(x);
            }
        }
        q--;
    } 
    return 0;
}



