#include<bits/stdc++.h>
#include<cmath>
#include<algorithm>
using namespace std;

class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {
	    int gap=m+n,temp;
	    gap=ceil(gap/2.0);
	    while(gap>0){
	        int first=0,second=gap;
	        for(int i=0;i<m+n-gap;i++){
	                if(second<n){
	                    if(arr1[first]>arr1[second]){
    	                    swap(arr1[first],arr1[second]);
	                    }
	                }
	                else if(second>=n&&first<n){
	                    if(arr1[first]>arr2[second-n]){
    	                    swap(arr1[first],arr2[second-n]);
	                    }
	                }
	                else if(second>=n&&first>=n){
	                    if(arr2[first-n]>arr2[second-n]){
    	                    swap(arr2[first-n],arr2[second-n]);
	                    }
	                }
	                first++;
	                second++;
	            }
	            //cout<<gap<<endl;
	            if(gap>1){
	                gap=ceil(gap/2.0);
	            }
	            else
	                gap=0;
	        }
	    }
};
int main(int argc, char const *argv[])
{
	Solution ob;
	int arr1[]={1,3,5,7};
	int arr2[]={0,2,6,8,9};
	ob.merge(arr1,arr2,4,5);
	for(int i=0;i<4;i++)
		cout<<arr1[i]<<" ";
	for(int i=0;i<5;i++)
		cout<<arr2[i]<<" ";
	return 0;
}