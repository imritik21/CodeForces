#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int DigitSum(int n){
    if(n==0) return 0;
    return DigitSum(n/10)+n%10;
}
int main(){
    int n;
    cin>>n;
    int res=DigitSum(n);
    cout<<res<<endl;
}