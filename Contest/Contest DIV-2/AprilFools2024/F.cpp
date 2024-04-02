#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    int cnt1=0,cnt2=0;
    char arr[22][22];
    for(int i=0;i<22;i++){
        for(int j=0;j<22;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='0') cnt1++;
            else if(arr[i][j]=='1') cnt2++;
        }
    }
    cout<<abs(cnt2-cnt1)+1<<endl;
}
