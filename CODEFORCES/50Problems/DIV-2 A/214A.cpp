#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    int n,m;
    cin>>n>>m;
    int cnt=0;
    for(int a=0;a*a<=n && a<=m;a++){
        int b = n- a*a;
        if((a+b*b)==m){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
