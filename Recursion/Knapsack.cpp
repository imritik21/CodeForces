#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
/*
INPUT
3 8
3 30
4 50
5 60

OUTPUT
90
*/
int helper(int index,int left,int weight[],int value[],int n){
    if(index==n){
        return 0;
    }
    if(left>=weight[index]){
        return max(helper(index+1,left,weight,value,n),helper(index+1,left-weight[index],weight,value,n)+value[index]);

    }
    else{
        return helper(index+1,left,weight,value,n);
    }
}
int main(){
    int n,w;
    cin>>n>>w;
    int weight[n],value[n];
    for(int i=0;i<n;i++){
        cin>>weight[i]>>value[i];
    }
    cout<<helper(0,w,weight,value,n)<<endl;
}
