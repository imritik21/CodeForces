#include<bits/stdc++.h>
 using namespace std;
 #define int  long long
 #define endl '\n' 
 signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=1;i<=n;i++) cin>> arr[i]; 

        int pos=0;
        int rem_neg=0;
        for(int i=1;i<n;i++){
            if(arr[i]>0){
                pos+=arr[i];
            }
            else
            {
                // pos = 4, arr[i]= -3
                // pos = 1, arr[i]= 0
                if(pos >= abs(arr[i]))
                {
                    pos -= abs(arr[i]);
                }
                // pos = 4, arr[i]= -5
                // pos= 0, arr[i]= 1
                else
                {
                    rem_neg += (abs(arr[i])-pos); // 5-4= 1 // cost
                    pos=0;
                }
            }
        }
        cout<<rem_neg<<endl;
    }
 }