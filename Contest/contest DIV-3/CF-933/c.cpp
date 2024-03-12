#include <bits/stdc++.h>
using namespace std;

int minCharToDel(string& str){
    int n=str.length();
    int cnt=0;
    for(int i=0;i<n-2;i++){
        if((str[i]=='p' && str[i+1]=='i' && str[i+2]=='e') ||
        (str[i]=='m' && str[i+1]=='a' && str[i+2]=='p')) {
            cnt++;
            i+=2;
        }
    }
    return cnt;
}
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        string str;
        cin>>str;
        
        cout<<minCharToDel(str)<<endl;
    }
}
