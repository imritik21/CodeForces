#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool isPowOf2(int n){
    if((n & n-1)==0) return true;
    else return false;
}
int main(){
    int n;
    cin>>n;
    if(isPowOf2(n)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}