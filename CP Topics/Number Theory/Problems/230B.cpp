#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const int N = 1e7+7;
int seive[N];
void solve(){
    fill(seive,seive+N+1,true);
    seive[0]=seive[1]=false;
    for(int i=2;i*i<N;i++){
        if(seive[i]==true){
            for(int j=i*i;j<N;j+=i){
                seive[j]=false;
            }
        }
    }
}
int main(){
    ll n;cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    solve();
    for(int i=0;i<n;i++){
        ll temp = sqrt(arr[i]);
        if(arr[i]==temp*temp && seive[temp]==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
