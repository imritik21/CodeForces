// 2. define three num x,y and p. Compute x^y%p in log
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int BinaryExpo(int x,int y,int p){
    int ans=1;
    while(y>0){
        if(y%2 == 1){ 
            ans=x*ans;
        }
        // if not odd or not set
        x=x*x;
        y=y>>1;
    }
    return ans%p;
}
void solve()
{
    int x,y,p;
    cin>>x>>y>>p;
    cout<<BinaryExpo(x,y,p)<<endl;
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
