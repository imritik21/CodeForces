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
    
    string str = "abc/res/12/res1";

    vector<string> vec;
    string curr="";
    for(int i=0;i<str.size();i++){
        if(str[i]=='/'){
            vec.push_back(curr);
            curr="";
            i++;
        }
        curr+=str[i];
    }
    if(curr!=" ")vec.push_back(curr);

    // for(auto& ele:vec)cout<<ele<<" ";
    map<string
    

    return 0;
}
