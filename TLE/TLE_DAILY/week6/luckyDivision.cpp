#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
bool islucky(int n){
    while(n>0){
        if(n%10 !=7 && n%10 !=4){
            return false;
        }
        n/=10;
    }
    return true;
}
signed main()
{
    int n;
    cin >> n;
    bool flag=false;
    for(int i=1;i<=n;i++){
        if(n%i==0 && islucky(i)){
            flag=true;
        }
    }
    cout<<(flag?"YES":"NO");
}