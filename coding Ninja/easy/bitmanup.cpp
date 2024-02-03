#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    int n;
    cin>>n;
    int bin[32];
    int i=0;
    while(n>0){
        bin[i]= n%2;
        n=n/2;
        i++;
    }
    for(int j=i-1;j>=0;j--){
        cout<<bin[j];
    }
}