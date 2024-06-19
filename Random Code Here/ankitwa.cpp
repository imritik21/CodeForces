#include <iostream>
#include <vector>
#include <string>
#include<bits/stdc++.h>
using namespace std;

int longestSubsequenceWithoutDisruption(const string &a, const string &b) {
    int n = a.size();
    int m = b.size();
    int ans=0;
    for(int len=1;len<=min(n,m);len++){
        for(int i=0; i+len <= n; i++){
            for(int j=0; j+len<= m; j++){
                if(a.substr(i,len)==b.substr(j,len)){
                    ans = max(ans,len);
                }
            }
        }
    }
    return ans;
}

int main() {
    string a = "ddcc";
    string b = "dc";
    int result = longestSubsequenceWithoutDisruption(a, b);
    cout << "Length of longest subsequence without disruption: " << result << endl;
    return 0;
}
