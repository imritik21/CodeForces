#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
        }
        for(int i=1;i<sum;i++){
            if(i*i==sum){
                cout<<"YES"<<endl;
            }
        }
        cout<<"NO"<<endl;
    }
}