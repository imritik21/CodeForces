#include<bits/stdc++.h>
using namespace std;
#define int  long long
#define endl '\n'
signed main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int ei=0,oi=0,ee=0,oe=0;
        int nm=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                ei++;
            }
            else{
                oi++;
            }
            if(arr[i]%2==0){
                ee++;
            }
            else{
                oe++;
            }
            if(i%2!=arr[i]%2){
                nm++;
            }
        }
        if(ei!=ee || oi!=oe){
            cout<<"-1"<<endl;
            continue;
        }
        cout<<nm/2<<endl;
    }
}