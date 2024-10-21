#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n,k;
    cin>>n>>k;

    vector<int> arr(n);
    for(auto &it:arr)cin>>it;

    multiset<int> low,high;
    // same as sliding window median problem
    // we will maintain two multiset
    ll sum1=0,sum2=0;
    for(int i=0;i<n;i++){
        
        low.insert(arr[i]);
        sum1+=arr[i];

        high.insert(*low.rbegin());
        sum2+=*low.rbegin();

        sum1-=*low.rbegin();
        low.erase(low.find(*low.rbegin()));

        if(low.size()<high.size()){
            low.insert(*high.begin());
            sum1+=*high.begin();

            sum2-=*high.begin();
            high.erase(high.find(*high.begin()));
        }
        
        if(i>=k-1){
            ll lowSum=0,highSum=0;
            ll currWindowCost=0;
            ll median=*low.rbegin();
            // if(k&1){
            //     median = *low.rbegin();
            // }
            // else median = (*low.rbegin()+*high.begin())/2;
        
            lowSum = ((k+1)/2)*median - sum1;
            highSum = sum2-(k-(k+1)/2)*median;
            currWindowCost = lowSum+highSum;

            cout<<currWindowCost<<" ";
            // remove out of window ele
            int out = arr[i-k+1];
            if(out<=*low.rbegin()) {
                low.erase(low.find(out));
                sum1-=out;
            }
            else {
                high.erase(high.find(out));
                sum2-=out;
            }
        }
    }
    return 0;
}
