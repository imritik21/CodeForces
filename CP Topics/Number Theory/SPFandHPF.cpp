#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
// application of Seive

// finding smallest prime factor
// TC- O(nlog(logn));
const int N = 1e7;
int spf[N];
int hpf[N];
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
}
// for lagrest prime factor
// initialy all no was marked as i
// for eg hpf[6]=3 not 2
// so we'll not start from i*i to save TC
// rather we will again mark it with next prime
void solvehpf()
{
    for(int i=0;i<N;i++){
        hpf[i]=i; // initially
    }
    for(int i=2;i<N;i++){
        if(hpf[i]==i){
            // not this will mark all multiple of i with i
            for(int j=2*i;j<N;j+=i){
                hpf[j]=i;
            }
        }
    }
    // TC-O(nlogn);
}
int main(){
    int n;
    cin>>n;
    solvespf();
    solvehpf();
    cout<<spf[n]<<endl;
    cout<<hpf[n];
}
