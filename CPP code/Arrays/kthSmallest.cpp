#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int l,int r){
    int pivot=arr[l];
    int i=l+1;
    do{
        while(arr[i]<=pivot)
            i++;
        while(arr[r]>pivot)
            r--;
        if(i<r)
            swap(&arr[i],&arr[r]);
    } while(i<r);
    
    swap(&arr[l],&arr[r]);
    
    return r;
}
int kthSmallest(int arr[], int l, int r, int k) {
    int pi;
    pi=partition(arr,l,r);
    if(pi+1==k)
        return arr[pi];
    else if(pi<k)
        return kthSmallest(arr,pi+1,r,k);
    else
        return kthSmallest(arr,l,pi,k);
        
    return -1;
}

int main(){
    int arr[]={7,10,4,3,20,15};
    int pi=partition(arr,0,5);
    cout<<arr[pi]<<endl;
    for(int i=0;i<6;i++)
        cout<<arr[i]<<" ";
    
    return 0;
}