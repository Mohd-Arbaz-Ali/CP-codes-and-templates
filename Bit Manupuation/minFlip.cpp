#include<iostream>
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int i=0,x,y,z,count=0;
        while((a|b)!=c){
            x=a & (1<<i);
            y=b & (1<<i);
            z=c & (1<<i);
            if((x|y)!=z){
                if(z==1){
                    a=a|(1<<i);
                    count++;
                }
                else{
                    if(x>=1&&y>=1){
                        a=a^(1<<i);
                        b=b^(1<<i);
                        count+=2;
                    }
                    else if(x>=1){
                        a=a^(1<<i);
                        count++;
                    }
                    else{
                        b=b^(1<<i);
                        count++;
                    }
                }
            }
            i++;
        }
        return count;
    }
};

int main(){
    int a=2,b=6,c=5;
    Solution obj;
    int count=obj.minFlips(a,b,c);
    cout<<count;
    return 0;
}