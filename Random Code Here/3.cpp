#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main() {
    int n,k;
    cin >> n>>k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        if(i==k){
            continue;
        }
        else{
            cout<<arr[i]<<" ";
        }
    }

    return 0;
}
