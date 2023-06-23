#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    int ar[n];
    
    for(int i=0;i<n;i++)
        cin>>ar[i];

    int low=0;  int high=n-1;
    while(low<=high){
        if(ar[low]<0)
            low++;
        if(ar[high]>=0)
            high--;
        if((ar[low]>=0)&&(ar[high]<0)&&low<=high){
            swap(ar[low],ar[high]);
        }
    }

    for(int i=0;i<n;i++)
        cout<<ar[i]<<" ";

    return 0;
}