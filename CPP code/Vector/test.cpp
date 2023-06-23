#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<int> V;
    int n,a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        V.push_back(a);
    }  
    sort(V.begin(),V.end());
    for(int i=0;i<n;i++){
        cout<<V[i]<<" ";
    } 
    return 0;
}
