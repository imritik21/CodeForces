#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    string str;
    cin >> str;
    // oddCount odd times && more than 1 -- NOT POSSIBLE   acccbbba     bcccb
    // evenCount     aabb  abbacc   acbbca
    map<char, int> mp;
    for (auto &ch : str)
        mp[ch]++;
    int OddCount = 0;
    // vector<char,int> freq;
    for (auto &ele : mp)
    {
        if (ele.second % 2 != 0)
        {
            OddCount++;
        }
        if(OddCount>1){
            cout<<"NO SOLUTION"<<endl;
            return;
        }
    }
    // A=6 c=2 B=1  store and if even divide them in half and make string half then just append
    string ans="";
    char c = ' ';
    for(auto& ch:mp){
        if(ch.second%2==1){
            c=ch.first;
        }
        if(ch.second%2==0){
            for(int i=0;i<ch.second/2;i++){
                ans+=ch.first;
            }
        }
    }
    bool f=false;
    if(c!=' '){
        for(int i=0;i<mp[c];i++)ans+=c;
        f=true;
    }
    int n = ans.size();
    if(f){
        n-=mp[c];
    }
    for(int i=n-1;i>=0;i--){
        ans.push_back(ans[i]);
    }
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solve();
    return 0;
}
