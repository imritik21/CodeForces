#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int countDiv(int n){
    int cnt=0;
    for(int i=1;i*i<=n;i++){
        if(n%i ==0)
        cnt++;

        if(i != n/i)
        cnt++;
    }
    return cnt;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++ ){
        cout<<countDiv(i)<<"\n";
    }
    return 0;

    // O( N*sqrtN)
}
