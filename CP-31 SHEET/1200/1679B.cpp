#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n+1);
    ll sum = 0;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    
    ll globalVal = -1;
    vector<ll> individual(n+1, -1);
    ll currentTime = 0;
    ll globalTime = -1;
    
    while(q--){
        currentTime++;
        ll type;
        cin >> type;
        if(type == 1){
            ll idx, newVal;
            cin >> idx >> newVal;
            ll curVal;
            if(globalTime == -1 || individual[idx] > globalTime){
                curVal = arr[idx];
            } else {
                curVal = globalVal;
            }
            sum = sum - curVal + newVal;
            arr[idx] = newVal;
            individual[idx] = currentTime; 
            cout << sum << "\n";
        }
        else if(type == 2){
            ll x;
            cin >> x;
            sum = n * x;
            globalVal = x;
            globalTime = currentTime;
            cout << sum << "\n";
        }
    }
    
    return 0;
}
