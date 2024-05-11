#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    ll k,n,w;
    cin>>k>>n>>w;
    ll totalCost=0;
    for(int i=1;i<=w;i++){
        totalCost=totalCost+k*i;
    }
    if(totalCost-n<0) cout<<0<<endl;
    else
    cout<<totalCost-n<<endl;
}
