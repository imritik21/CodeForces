#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    string s, w;
    getline(cin,s);
    cin>> w;

    vector<string> v;
    string str = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] != ' '){
            str += s[i];
        } else {
            v.push_back(str);
            str = "";
        }
    }
    // Add the last word
    if(!str.empty()) {
        v.push_back(str);
    }

    unordered_map<string, int> mp;
    for(int i = 0; i < v.size(); i++){
        mp[v[i]]++;
    }

    int cnt = 0;
    cnt = mp[w];
    
    cout << cnt << endl;
    return 0;
}
