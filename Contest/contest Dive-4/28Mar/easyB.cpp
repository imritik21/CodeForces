#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    int tc;cin>>tc;
    while(tc--){
        int n;cin>>n;
        string a="";
        string b="";

        for(int i=1;i<=n;i++){
            a+= (i%2)?"##":"..";
            b+=(i%2)?"..":"##";
        }
        for(int i=1;i<=n;i++){
            if(i%2){
                cout<<a<<'\n'<<a<<'\n';
            }
            else 
                cout<<b<<'\n'<<b<<'\n';
        }
    }
}
