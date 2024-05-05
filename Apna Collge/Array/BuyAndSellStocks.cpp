#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    int n=6;
    int prices[]={7,1,5,3,6,4};
    int mx=0;
    int buyPrice=INT_MAX;
    int profit=0;
    for(int i=0;i<n;i++){
        if(buyPrice<prices[i]){
            profit=prices[i]-buyPrice;
            mx=max(mx,profit);
        }
        else{
            buyPrice=prices[i];
        }
    }
    cout<<mx<<endl;
}
