
// 1. wap to find the first and last m digits from k power of m
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int fastExpo(int a,int b){
    int ans=1;
    while(b>0){
        if(b%2 == 1){ 
            // b is odd
            // add ans to power
            ans=a*ans;
        }
        a=a*a;
        b=b>>1;
    }
    return ans;
}
void solve()
{
    int k,m;
    cin>>k>>m;
    ll num = fastExpo(k,m);
    vector<int> digits;
    while(num>0){
        int rem = num%10;
        num/=10;
        digits.push_back(rem);
    }
    reverse(digits.begin(),digits.end());
    // for(auto ele:digits)cout<<ele<<" ";
    cout<<"M digits from start : ";
    for(int i=0;i<m;i++)cout<<digits[i]<<" ";
    cout<<endl;
    cout<<"M digits from end : ";
    int last=digits.size()-1;
    while(m>0){
        cout<<digits[last]<<" ";
        last--;
        m--;
    }
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int test;
    cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
