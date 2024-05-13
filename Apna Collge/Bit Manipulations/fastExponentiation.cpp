#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int fastExpo(int a,int b){
    int ans=1;
    while(b>0){
        if(b%2 == 1){ // if bit is set
            // b is odd
            // add ans to power
            ans=a*ans;
        }
        // if not odd or not set
        a=a*a;
        b=b>>1;
    }
    return ans;
}
int main(){
    int n,x;
    cin>>n>>x;
    int ans=fastExpo(n,x);
    cout<<ans<<endl;
}
