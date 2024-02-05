#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    int n;
    cin>>n;
    int arr[n];
    set<int> stt;
    for(int i=0;i<n-1;i++)
    {   
        cin>>arr[i];
        stt.insert(arr[i]);
        
    }
    for(int i=0;i<n;i++){
        if(!stt.count(arr[i])){
            cout<< i;
            break;
        }
    }
}
