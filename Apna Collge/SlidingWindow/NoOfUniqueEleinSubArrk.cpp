// TO find number of Unique elements
// for a window
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> arr = {1,1,2,2};
    int n = arr.size();
    int k = 2;

    map<int,int> mp;
    int cnt=0;
    for(int i=0;i<k;i++){
        mp[arr[i]]++;
    }
    cnt+=mp.size();
    cout<<cnt<<endl;
    for(int i=k;i<n;i++){
        mp[arr[i]]++;
        mp[arr[i-k]]--;
        if(mp[arr[i-k]]==0){
            mp.erase(arr[i-k]);
        }
        cnt+=mp.size();
        cout<<cnt<<endl;
    }
    cout<<"finall ";
    cout<<cnt<<endl;
    return 0;
}
