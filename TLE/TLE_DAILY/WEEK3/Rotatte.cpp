/*https://atcoder.jp/contests/abc309/tasks/abc309_b*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    int n;
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            arr[i][j]=s[j]-'0'; // typecast into int
        }
    }
    // basically we are rotating the elements by assigning the prev value 
    //      1 1  after rotation   0 1
    //      0 1                   1 1
    int temp=arr[0][0];
    for(int j=0;j<n-1;j++){
        arr[j][0]=arr[j+1][0];
    }
    for(int j=0;j<n-1;j++){
        arr[n-1][j]=arr[n-1][j+1];
    }
    for(int j=n-1;j>0;j--){
        arr[j][n-1]=arr[j-1][n-1];
    }
    for(int j=n-1;j>1;j--){
        arr[0][j]=arr[0][j-1];
    }
    arr[0][1]=temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}