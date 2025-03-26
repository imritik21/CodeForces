#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
long long countOfSubstrings(string word, int k)
{
    
    
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string word = "iqeaouqi";
    int k=2;
    long long ans = countSubstr(word, k);
    long long res = countSubstr(word, k + 1);
    cout<<ans<<" "<<res<<endl;
    
    return 0;
}
