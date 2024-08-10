#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main(){
    int n,k;
    cin>>n>>k;
    // cal factors
    vector<int> primes;
    for(ll i=2;i*i<=n;i++){
        while(n%i ==0){
            primes.push_back(i);
            n/=i;
        }
    }
    if(n>1) // this means n is prime no
    primes.push_back(n);
    // for(int i=0;i<primes.size();i++) cout<<primes[i]<<" ";
    // 36 = 2 2 3 3  k=2  ttl=4     64 = 2 2 2 2 2 2  k=3 total = 6
    //  2 (2*3*3)                2 2 16     k-1 tk jao and baaki ka mult
    if(k>primes.size()){
        cout<<-1<<endl;
    }
    else{
        ll left=1;
        for(int i=k-1;i<primes.size();i++){
            left*=primes[i];
        }
        for(int i=0;i<k-1;i++){
            cout<<primes[i]<<" ";
        }
        cout<<left<<endl;
    }
    
}
