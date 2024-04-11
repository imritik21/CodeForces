#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    ll n,m,a;
    cin>>n>>m>>a;
    n = n/a + (n%a!=0); // ceil
    m = m/a + (m%a!=0); // ceil
    cout<<n*m<<endl;
} 
