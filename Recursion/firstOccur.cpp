#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int firstOccur(vector<int>& vec,int k,int i){
    if(i==vec.size()){
        return -1;
    }
    if(vec[i]==k){
        return i;
    }
    return firstOccur(vec,k,i+1);
}
int lastOccur(vector<int>& vec,int k,int i){
    if(i<0){
        return -1;
    }
    if(vec[i]==k){
        return i;
    }
    return lastOccur(vec,k,i-1);
}
int main(){
    // int ?
    vector<int> vec{5,5,5,5};
    int res=firstOccur(vec,5,0);
    int res2=lastOccur(vec,5,8);
    cout<<res<<endl;
    cout<<res2<<endl;
}
