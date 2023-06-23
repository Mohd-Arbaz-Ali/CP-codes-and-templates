#include <iostream>
#include<stack>
using namespace std;

void span(int ar[],int n){
    stack<int> st;
    int s[n]={0};
    for(int i=0;i<n;i++){
        while(!st.empty() && ar[st.top()]<=ar[i]){
            st.pop();
        }
        s[i]=((st.empty()) ? i+1 : i-st.top());
        st.push(i);
    }
    for(int i=0;i<n;i++){
        cout<<s[i]<<" ";
    }   
    cout<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ar[n];
        for(int i=0;i<n;i++)
            cin>>ar[i];
       span(ar,n);
    }
    return 0;
}