#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int fastExpo(int a, int b)
{
    int ans = 1;
    a = a % mod; 

    while (b > 0)
    {
        if (b % 2 == 1)
        {                                
            ans = (1LL * ans * a) % mod; 
        }
        a = (1LL * a * a) % mod; 
        b = b >> 1;             
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    // 0000 0001 0010 0011 0100 0101 0110 0111 1000 1001 1010 1011 1100 1101 1110 1111
    ll res = fastExpo(2,n);
    cout<<res<<endl;
    return 0;
}
