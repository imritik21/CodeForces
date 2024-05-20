#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

const int N=1e7;
int primes[N];

void solve(){
    // bool primes[n+1];
    // initialize every index with ture;
    fill(primes,primes+N+1,true);
    primes[0]=primes[1]=false;
    for(int i=2;i*i<=N;i++){
        if(primes[i]){
            for(int j=i*i;j<=N;j+=i){
                primes[j]=false;
            }
        }
    }
}
int main (){
    int n;
    cin>>n;
    solve();
    cout<<primes[n];
    
}