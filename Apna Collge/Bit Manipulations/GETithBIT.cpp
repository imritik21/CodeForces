#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void getithBit(int n,int index){
    int bitmask=1<<index; // to get ith bit 1 leftshift ith and then & to get the bit
    if((n & bitmask) == 0){
        // even
        cout<<"0"<<endl;
    }
    else{
        cout<<"1"<<endl;
    }
}
int setithBIT(int n,int i){ // reach ith bit using 1<<i and then | to set it
    int bitmask=1<<i;
    return n|bitmask;
}
int clearithBIT(int n,int i){
    int bitmask=~(1<<i);
    return n & bitmask;
}
int updateithBit(int n,int i,int newBit){
    if(newBit==0){
        return clearithBIT(n,i);
    }
    else
    return setithBIT(n,i);
}
int clearLastithBit(int n,int i){
    // eg n=1111 i=2
    // ans =1100 this can be done by setting bitmask as ((-1)<<i) // as -1=111111111
    int bitmask= (-1<<i);// then by doing & 
    return n & bitmask;
}
int main(){
    int n,index;
    cin>>n>>index;
    // getithBit(n,index);
    // cout<<setithBIT(n,index);
    // cout<<clearithBIT(n,index);
    // cout<<updateithBit(n,index,10);
    cout<<clearLastithBit(n,index);
}
