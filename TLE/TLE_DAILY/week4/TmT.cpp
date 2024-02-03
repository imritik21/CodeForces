#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        string str;
        cin>>str;
        vector<int>T,M;
        for(int i=0;i<n;i++){
            if(str[i]=='T'){
                T.push_back(i);
            }else{
                M.push_back(i);
            }
        }
        bool flag=true;
        if(T.size()!=M.size()*2){
            flag=false;
        }else{
            int x=M.size();
            for(int i=0;i<x;i++){
                if(!(T[i]<M[i] && M[i]<T[i+x])){
                    flag=false;
                }
            }
        }
        cout<<(flag?"YES":"NO")<<endl;
    }
}