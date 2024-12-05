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
    string s,t;
    cin>>s>>t;
    vector<int> freq(26,0);
    for(auto i:t)freq[i-'a']++;
    ll cnt=0;
    for(int l=0,r=0;r<n;r++){
        freq[s[r]-'a']--;
        while(*min_element(freq.begin(),freq.end())<0){
            freq[s[l]-'a']++;
            l++;
        } // this while loop validate the l 
        cnt+=(r-l+1);// total no of possible substr at given r
    }
    cout<<cnt<<endl;
    return 0;
}
