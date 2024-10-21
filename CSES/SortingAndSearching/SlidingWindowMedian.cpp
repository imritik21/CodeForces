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

    ll n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(auto &it:arr)cin>>it;
    // we'll use two multiset as it store in  sorted way
    multiset<int> low, high;
    // steps are pretty simple
    // 1. insert in low set
    // 2. insert largest from low to high
    // 3. check the cond i.e  low==high or low==high-1
    // 4. if not then remove lowest ele from high and insert in low
    // 5. if odd window then median is largest ele of low
    //    else avg of largest of low and smallest of high
    // 6. for next iteration remove the i-k+1 th ele if present in low or high
    for(int i=0;i<n;i++){
        low.insert(arr[i]);
        high.insert(*low.rbegin());
        low.erase(low.find(*low.rbegin()));

        if(low.size()<high.size()){
            low.insert(*high.begin());
            high.erase(high.find(*high.begin()));
        }
        // slide
        if(i>=k-1){
            if(k&1){
                cout<<*low.rbegin()<<" ";
            }
            else cout<<min(*low.rbegin(),*high.begin())<<" ";

            // remove 
            if(arr[i-k+1]<=*low.rbegin())
            low.erase(low.find(arr[i-k+1]));
            else
            high.erase(high.find(arr[i-k+1]));
        }
    }
    return 0;
}
