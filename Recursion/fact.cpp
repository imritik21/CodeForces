#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int fact(int n){
    if(n==0){
        return 1;
    }
    return fact(n-1)*n;
}
int main(){
    int n;
    cin>>n;
    cout<<fact(n);
}
