#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const int N=1e7;
int SPF[N],HPF[N];
void solveSPF(){
    // initially fill with numbers
    // and instead of making it false assign it with i 
    for(int i=0;i<N;i++){
        SPF[i]=i;
    }
    for(int i=2;i*i<N;i++){
        if(SPF[i]==i){
            for(int j=i*i;j<N;j+=i){
                if(SPF[j]==j){
                    SPF[j]=i;
                }
            }
        }
    }
}
void solveHPF(){
    // initlally fill with itself
    for(int i=0;i<N;i++){
        HPF[i]=i;
    }
    for(int i=2;i<N;i++){
        if(HPF[i]==i){
            for(int j=2*i;j<N;j+=i){
                HPF[j]=i;
            }
        }
    }
}

int main(){
    // spf calc smallest prime factor 
    // hpf calcs largest prime factor 
    int n;cin>>n;
    solveSPF();solveHPF();
    cout<<SPF[n]<<" "<<HPF[n];
    cout<<endl;
    // now if you want to find prime factors of a number
    vector<int> prime_factors;
    while(n>1){
        prime_factors.push_back(SPF[n]);
        n/=SPF[n];
    }
    for(int i=0;i<prime_factors.size();i++) cout<<prime_factors[i]<<" ";
}
