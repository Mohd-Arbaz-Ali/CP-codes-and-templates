#include<bits/stdc++.h>
using namespace std;

int partition(char pivot,char *arr,int low,int high){
        int i=low;
        for(int j=low;j<high;j++){
            if(arr[j]<pivot){
                swap(arr[i],arr[j]);
                i++;
            }
            else if(arr[j]==arr[i]){
                swap(arr[high],arr[j]);
                j--;
            }
        }
        swap(arr[high],arr[i]);
        return i;
    }
    void quickMatch(char *nuts,char* bolts,int low,int high){
        if(low<high){
            int pivot=partition(bolts[high],nuts,low,high);
            partition(nuts[pivot],bolts,low,high);
            quickMatch(nuts,bolts,low,pivot-1);
            quickMatch(nuts,bolts,pivot+1,high);
        }
    }
	void matchPairs(char nuts[], char bolts[], int n) {
	    quickMatch(nuts,bolts,0,n-1);
	}

int main()
{

    char nuts[] = {'^', '&', '%', '@', '#', '*', '$', '~', '!'};
    char bolts[] = {'~', '#', '@', '%', '&', '*', '$' ,'^', '!'};
    int n=sizeof(nuts)/sizeof(nuts[0]);
    matchPairs(nuts,bolts,n);
    for(int i=0;i<n;i++)
        cout<<nuts[i]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<bolts[i]<<" ";
    cout<<endl;
    return 0;
}