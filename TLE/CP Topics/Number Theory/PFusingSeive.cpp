#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
// to use eive for prime factorisation, we make the seive
// array that stores the smallest pf of a num
//
// to retrieve the values, we can repeatedly divide the
// current number by the smallest prime factor

// TC- precomputation+O(nlog(logn)); 
const int N = 1e7;
int spf[N];
void solvespf()
{
    for(int i=0;i<N;i++){
        spf[i]=i; // initially
    }
    for(int i=2;i*i<N;i++){
        if(spf[i]==i){
            for(int j=i*i;j<N;j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }

    // prime factors of n;
    // vector<int> prime_factors;
    // W.C  TC=O(logn)
    // while(N>1){
    //     prime_factors.push_back(spf[N]);
    //     N/=spf[N];
    // }
}
int main(){
    int n;
    cin>>n;
    solvespf();
    // cout<<spf[n];
    vector<int> prime_factors;
    while(n>1){
        prime_factors.push_back(spf[n]);
        n/=spf[n];
    }
    for(int i=0;i<prime_factors.size();i++){
        cout<<prime_factors[i]<<" ";
    }
}
