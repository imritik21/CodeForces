#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
string toBin(int n){
    if (n == 0) return "0"; // Handle the case where n is 0.

    string binary = "";
    while (n > 0) {
        // Append the remainder (0 or 1) to the binary string.
        binary = (n % 2 == 0 ? "0" : "1") + binary;
        n /= 2; // Divide the number by 2 to process the next bit.
    }
    return binary;
}
string toBinary(int n){
    string str="";
    for(int i=30;i>=0;i--){
        str+=to_string(((n>>i)&1));
    }
    return str;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int c;
    cin>>c;
    int bit_cnt = (int)log2(c)+1;
    int a=0,b=0;
    vector<int> set_bits;
    for(int i=0;i<bit_cnt;i++){
        if(c&(1<<i)){
            set_bits.push_back(i);
        }
        else{ // if bit is 0 in c set in both a and b
            a |= (1<<i);
            b |= (1<<i);
        }
    }
    int sz = 1<<set_bits.size();
    // for(auto ele:set_bits)cout<<ele<<" ";
    // cout<<endl;
    // cout<<sz<<endl;
    ll ans=-1;
    // generate subsets and find the maximum
    for(int mask =0;mask<sz;mask++){
        int a_copy = a, b_copy= b;
        for(int j=0;j<set_bits.size();j++){
            // ya to ith bit ko a me set kro ya b 
            // all possible me basically
            // jth agr mask me set hai to a me set kr dete h wrna b me kr dete h
            if(mask&(1<<j)){
                a_copy |= (1<<set_bits[j]);
            }
            else{
                b_copy |= (1<<set_bits[j]);
            }
        }
        ans=max(ans,a_copy*1LL*b_copy);
    }
    // cout<<ans<<endl;
    cout<<(1<<2)<<endl;
    return 0;
}
