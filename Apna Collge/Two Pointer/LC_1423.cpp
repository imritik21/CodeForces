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
    vector<int> cards = {1,2,3,4,5,6,1};
    int k = 3;
    int n = cards.size();
    int ans=0;
    for(int i=0;i<k;i++){
        ans+=cards[i];
    }
    int res=ans;
    int last_idx=n-1;
    for(int i=k-1;i>=0;i--){
        ans-=cards[i];
        ans+=cards[last_idx];
        res=max(res,ans);
        last_idx--;
    }
    cout<<res<<endl;
    return 0;
}
