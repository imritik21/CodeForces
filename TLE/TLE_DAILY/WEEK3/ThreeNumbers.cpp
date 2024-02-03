#include<bits/stdc++.h>
 using namespace std;
 #define int  long long
 #define endl '\n' 
 signed main(){
    int k,s;
    cin>>k>>s;
    int x,y,z;
    int count=0;
    for(x=0;x<=k;x++){
        for(y=0;y<=k;y++){
            int z = s - x - y;
            if (z >= 0 && z <= k) {
                count++;
            }
        }
    }
    cout<<count<<endl;
 }