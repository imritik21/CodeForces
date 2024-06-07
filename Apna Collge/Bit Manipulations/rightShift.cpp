#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
string binaryNextNumber(string s) {
        // code here.
        int n = s.size();
        bool noZero =  true;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                s[i]='1';
                noZero = false;
                break;
            }
            else{
                s[i]='0';
            }
        }
        if(noZero){
            s = "1"+s;
        }
        // now
        while(s[0]=='0' && s.size()>1){
            s.erase(s.begin());
        }
        return s;
    }
bool hasAlternatingBits(int n) {
        ios_base::sync_with_stdio(false);
        int curr = n & 1;
        n=n>>1;
        while(n>0){
            int nextBit = n&1;
            if(curr==nextBit){
                return false;
            }
            curr = nextBit;
            n = n>>1;
        }
        // at last 
        return true;
    }
int main(){
    // cout<<(3>>2)<<endl;
    // cout<<(16&1);
    cout<<(3^1);
    // cout<<_builtin_popcount(3);
}
