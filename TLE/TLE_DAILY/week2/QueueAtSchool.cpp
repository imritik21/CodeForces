#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,time;
    cin>>n>>time;
    string s;
    cin>>s;
    for(int t=0;t<time;t++){
        for(int i=0;i<n-1;i++){
            if(s[i]=='B' && s[i+1]=='G'){
            swap(s[i],s[i+1]);
            i++;
            }
            
        }
    }
    cout<<s;
}