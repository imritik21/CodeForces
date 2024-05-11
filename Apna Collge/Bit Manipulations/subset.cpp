#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
/*Note that x << k corresponds to multiplying x by 2^k
, and x >> k corresponds
to dividing x by 2^k
rounded down to an integer*/
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    for(int mask=0;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                cout<<arr[i]<<" ";
            }
        }
        cout<<endl;
    }
}
