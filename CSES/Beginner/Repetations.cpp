#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    string s;
    cin>>s;
    int n=s.length();
    int cnt=1;
    int maxi=1;

    for(int i=0;i+1<n;i++){
        if(s[i]==s[i+1]){
            cnt++;
        }
        else{
            cnt=1;
        }
        maxi=max(maxi,cnt);
    }
    cout<<maxi<<endl;
}
