#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int mask=0;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            if(mask & (1<<i)){
                cout<<arr[i]<<" ";
            }
        }
        cout<<endl;
    }
}
