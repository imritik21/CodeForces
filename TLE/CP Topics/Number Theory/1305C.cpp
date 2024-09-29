#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,m;
    cin>>n>>m;
    vector<ll> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n>m){
        cout<<0<<endl;
        return 0;
    }
    ll ans=1;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans = (ans*abs(arr[i]-arr[j]))%m;
        }
    }
    cout<<ans<<endl;
    // using peigonhole principle
    // if n items are put into m containers with n>m

    // then at least one conatiner must contain more than one item
    // n=4 m=3
    // a = 10 11 12 13
    // ans= (abs(10-11)*(10-12)*(10-13)*(11-12)*(11-13)*(12-13));
    // ans= 
    // MOduluar Substraction
    //  abs(10-13)%3 = abs(10%3 - 13%3) = abs(1-1)%3 = 0
    // for n>m ans =0 always  using peigon hole princple values are repeated 
    // so obv abs(a-a) i will siply get 0
    // eg:
    // n=4 m=3
    // 1 2 4 5
    // 1 2 1 2 pretty obv mod will get repeated and which will result in 0
    // if not repeated then its guarantee that mod of 2 values with
    // m will be equal and if mod of 2 value equal so ans = 0 we saw above
    
    return 0;
}
