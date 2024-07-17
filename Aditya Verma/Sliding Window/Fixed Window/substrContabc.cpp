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
    string str = "bbacba";
    int n = str.size();
    int cnt=0;
    // brute
    for(int i=0;i<n;i++){
        int hash[3]={0};
        for(int j=i;j<n;j++){
            hash[str[j]-'a']=1;
            if(hash[0]+hash[1]+hash[2]==3){
                cnt+=(n-j);
                break;
            }
        }
    }
    cout<<cnt<<endl;
    // optimize
    cnt=0;
    int l=0,r=0;
    int hash[3]={0};
    while(r<n){
        hash[str[r]-'a']=1;
        if(hash[0]+hash[1]+hash[2]==3){
            cnt+=(n-r);
            l++;
        }
        r++;
    }
    cout<<cnt<<endl;
    return 0;
}
