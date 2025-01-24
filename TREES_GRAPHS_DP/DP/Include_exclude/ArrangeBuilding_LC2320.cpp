#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int countHousePlacements(int n){
    // similar approach as of cnt of binary string 
        // where no two 0's are consecutive
        // here too space can be in between maintain 2 dp
        // find the result for n by adding both side road and then mul for both side
    vector<int> dp_B(n+1,0),dp_Sp(n+1,0);
    dp_B[1]=1;
    dp_Sp[1]=1;

    for(int i=2;i<n+1;i++){
        dp_B[i] = dp_Sp[i-1]%mod;
        dp_Sp[i] = ( dp_Sp[i-1]+dp_B[i-1])%mod;
    }
    int sum = (dp_B[n]+dp_Sp[n])%mod;
    return (1LL*sum*sum)%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    cout<<countHousePlacements(n)<<endl;
    return 0;
}
