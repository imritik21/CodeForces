#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        string out;
        for(int i=0;i<n;i++){
            int count=0;
            while(count++ < 2 && i< n){
                out.push_back(s[i++]);
            }
            if(i<n-1 && (s[i]>= 'a' && s[i] <= 'e')&& (s[i+1]>='a' && s[i+1]<='e')){
                out.push_back(s[i++]);
            }
            out.push_back('.');
        }
        if(out.back()==' '){
            out.pop_back();
        }
        cout<<out<<"\n";
    }
    return 0;
}