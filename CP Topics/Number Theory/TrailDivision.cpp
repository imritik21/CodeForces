#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    ll n;
    cin>>n;
    vector<int> primes;
    for(ll i=2;i*i<=n;i++){
        while(n%i ==0){
            primes.push_back(i);
            n/=i;
        }
    }
    if(n>1) // this means n is prime no
    primes.push_back(n);
    for(int i=0;i<primes.size();i++) cout<<primes[i]<<" ";
}