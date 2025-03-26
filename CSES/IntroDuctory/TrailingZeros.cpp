#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
// void solve()
// {
// }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    // if n=20;
    // basically i have to count multiple of 2 andf 5
    // multiple of 10 = 2      multiple(10)
    // multiple of 5 and 2 = 2   min(5,2)
    //  239 - 23 + 
    int mul5 = n/5;
    int ans = mul5;
    while(mul5){
        ans+=mul5/5;
        mul5/=5;
    }
    cout<<ans<<endl;
    return 0;
}
