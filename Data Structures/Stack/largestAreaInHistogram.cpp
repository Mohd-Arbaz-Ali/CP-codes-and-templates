#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

long getMaxArea(long long arr[], int n){
    
    stack<int> s;
    long long i=0,max_area=INT_MIN,inx;
    for(i=0;i<n;i++){
        while(!s.empty() && arr[i]<arr[s.top()]){
            inx=s.top();
            s.pop();
            if(s.empty()){
                max_area=max(max_area,arr[inx]*i);
            }
            else{
                max_area=max(max_area,arr[inx]*(i-s.top()-1));
            }
        }
        s.push(i);
    }
    while(!s.empty()){
        inx=s.top();
        s.pop();
        if(s.empty()){
                max_area=max(max_area,arr[inx]*i);
            }
        else
            max_area=max(max_area,arr[inx]*(i-s.top()-1));
    }
    return max_area;
}

int main(int argc, char const *argv[])
{
    long long arr[]={6,2,5,4,4,1,6};
    cout<<getMaxArea(arr,7)<<endl;
    return 0;
}