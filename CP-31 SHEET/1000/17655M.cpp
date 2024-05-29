#include <iostream>
#include <vector>
using namespace std;

#define ll long long

ll gcd(ll a, ll b) { 
  if (b == 0) 
    return a; 
  return gcd(b, a % b); 
}

// Function to return LCM of two numbers  
ll lcm(ll a, ll b) { 
    return (a / gcd(a, b)) * b; 
}

void solve() {
    ll n; 
    cin >> n;
    vector<ll> divisors;
    
    // Find all divisors of n
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (n / i != i) {
                divisors.push_back(n / i);
            }
        }
    }
    
    ll a = 1, b = n - 1;
    ll ans = lcm(a, b);
    
    for (auto el : divisors) {
        ll sec = n / el;
        ll tempa = el * 1;
        ll tempb = el * (sec - 1);
        ll tempans = lcm(tempa, tempb);

        if (tempans < ans) {
            ans = tempans;
            a = tempa;
            b = tempb;
        }
    }
    
    cout << a << " " << b<<endl;
}

int main() {
    int tc;cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}
