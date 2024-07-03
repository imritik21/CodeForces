#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    string str;
    cin>>str;
    bool flag = false;
    for(int i=1;i<n;i++){
        if(str[i]<str[i-1]){
            cout<<"YES"<<endl;
            cout<<i<<" "<<i+1<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
