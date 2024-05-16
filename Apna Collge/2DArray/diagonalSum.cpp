#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    // print them in spiral way
    int sum=0;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(i==j){
    //             sum+=arr[i][j];
    //         }
    //     }
    // }
    for(int i=0;i<n;i++){
            sum += arr[i][i];
        }
    cout<<sum<<endl;
}
