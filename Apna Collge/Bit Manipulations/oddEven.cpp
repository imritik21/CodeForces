#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void oddEven(int n){
    int bitmask=1;
    if((n & bitmask) == 0){
        // even
        cout<<"Even"<<endl;
    }
    else{
        cout<<"ODD"<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    oddEven(n);
}
