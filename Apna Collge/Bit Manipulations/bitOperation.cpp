#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    int n;
    cin>>n;
    for(int i=31;i>=0;i--){
        if(n&(1<<i)) cout<<"1";
        else cout<<"0";
    }
}
