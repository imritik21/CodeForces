#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
//  n and k (1≤n≤10^9, 1≤k≤2⋅10^5).
int msb(int n) {
    if (n == 0) return -1;  
    return static_cast<int>(log2(n));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    ll n,k;
    cin>>n>>k;
    if(k>n){
        cout<<"NO"<<endl;
        return 0;
    }
    if(k< __builtin_popcount(n)){
        cout<<"NO"<<endl;
        return 0;
    }
    if(k==1 && (n&n-1)!=0){
        cout<<"NO"<<endl;
        return 0;
    }
    priority_queue<int> ans;

    while (n) {
        ans.push(pow(2, msb(n)));
        n -= pow(2, msb(n));
    }

    while (ans.size() < k) {
        int biggest = ans.top();
        ans.pop();
        ans.push(biggest / 2);
        ans.push(biggest / 2);
    }

    vector<int> results;
    while (!ans.empty()) {
        results.push_back(ans.top());
        ans.pop();
    }


    cout<<"YES"<<endl;
    for(auto el:results){
        cout<<el<<" ";
    }
    return 0;
}
