#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int count1(string s,int n){
    int count=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            count++;
        }
    }
    return count;
}
signed main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        // Input n characters using a for loop
        string s;
        for (int i = 0; i < n; ++i) {
            char ch;
            cin >> ch;
            s += ch;
        }
        string f;
        for (int i = 0; i < n; ++i) {
            char ch;
            cin >> ch;
            f += ch;
        }
        int cnt=0;
        if(count1(s,n)>count1(f,n)){
            int extra1= count1(s,n)-count1(f,n);
            cnt+=extra1;
        }
        for(int i=0;i<n;i++){
            if(f[i]=='1' && s[i]=='0'){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}