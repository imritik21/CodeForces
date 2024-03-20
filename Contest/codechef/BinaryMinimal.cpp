#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    int tc;cin>>tc;
    while(tc--){
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int count1=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') count1++;
        }
        if(k>=count1){
            int newLen=n-k;
            string a="";
            for(int i=0;i<newLen;i++){
                a+='0';
            }
            cout<<a<<endl;
        }
        else{
            for(int i=0;i<n;i++){
                if(k<=0){
                    break;
                }
                if(s[i]=='1'){
                    s[i]=0;
                    k--;
                }
            }
            cout<<s<<endl;
        }
    }
}
