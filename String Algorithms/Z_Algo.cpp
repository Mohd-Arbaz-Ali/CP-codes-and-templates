#include<bits/stdc++.h>

using namespace std;

vector<int> Z_Func(string &s){
    int n=s.size();
    vector<int>Z(n);
    int l=0,r=0;
    //Z[0]=n;
    for(int i=1;i<n;i++){
        if(i>r){
            l=r=i;
            while(r<n&&s[r-l]==s[r])
                r++;
            r--;
            Z[i]=r-l+1;
        }else{
            int j=i-l;
            if(Z[j]<r-i+1)
                Z[i]=Z[j];
            else{
                l=i;
                while(r<n&&s[r-l]==s[r])
                    r++;
                r--;
                Z[i]=r-l+1;
            }
        }
    }
    return Z;
}

int32_t main() {
    string s,t;
    cin>>s>>t;
    s=t+"$"+s;
    vector<int>Z=Z_Func(s);
    for(auto &i:Z)
        cout<<i<<" ";
    return 0;
}