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
    string s = "abcabc";
    int a=0,ab=0,abc=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='a'){
            a=2*a+1;
        }
        else if(s[i]=='b'){
            ab=2*ab+a;
        }
        else if(s[i]=='c'){
            abc=2*abc+ab;
        }
    }
    cout<<abc<<endl;
    return 0;
}
