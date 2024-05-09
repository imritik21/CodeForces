#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(str[i]=='a' && str[j]=='b' && str[k]=='c' ){
                    cnt++;
                }
            }
        }
    }
    cout<<cnt<<endl;
}

int main() {
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}
