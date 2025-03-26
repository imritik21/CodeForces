#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void permutations(string str,string ans)
{
    // base case
    if(str.size()==0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<str.size();i++){
        char curr = str[i];
        // remove ith char
        string rem = str.substr(0,i)+str.substr(i+1);
        permutations(rem,ans+curr);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string str = "abc";
    permutations(str,"");
    return 0;
}
