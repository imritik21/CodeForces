/*Vlad, like everyone else, loves to sleep very much.

Every day Vlad has to do n things, each at a certain time. For each of these things, he has an alarm clock set,
the i-th of them is triggered on hi hours mi minutes every day (0≤hi<24,0≤mi<60). Vlad uses the 24-hour time format,
 so after h=12,m=59 comes h=13,m=0 and after h=23,m=59 comes h=0,m=0
.

This time Vlad went to bed at H hours M minutes (0≤H<24,0≤M<60) and asks you to answer: how much he will be able to sleep until the next alarm clock.

If any alarm clock rings at the time when he went to bed, then he will sleep for a period of time of length 0
*/
/*https://codeforces.com/problemset/problem/1714/A*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int minn(int a,int b){
    return a<b?a:b;
}
signed main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n,H,M;
        cin>>n>>H>>M;
        int res=INT_MAX;
        int hr[n],min[n];
        for(int i=0;i<n;i++){
            cin>>hr[i]>>min[i];
        }
        for(int i=0;i<n;i++){
            int diff= (hr[i]*60+min[i])-(H*60+M);
            if(diff<0){
                diff+=1440;
            }
            res=minn(res,diff);
        }
        cout<<res/60<<" "<<res%60<<endl;
    }
}