#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


int main(){
    ios_base::sync_with_stdio(false);  cin.tie(nullptr);
    
    int a,b;
    cin>>a>>b;
    // swap withoud third var
    
    
    // a=b+a;
    // b=a-b;
    // a=a-b;

    // using binary
    a=b^a;
    b=a^b;
    a=a^b;
    cout<<a<<" "<<b; 
}
