#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int count=0;
    for(int i=n-1;i>=0;i--){
        for(int j=i-1;j>=0;j--){
            if(j<i && j>=(i-arr[i])){
                count++;
                break;
            }
            break;
        }
    }
    cout<<count<<endl;
}
