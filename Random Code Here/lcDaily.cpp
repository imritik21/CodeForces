#include<bits/stdc++.h>
using namespace std;
int getLucky(string s, int k)
{
    vector<string> ans;
    for (int i = 0; i < s.size(); i++)
    {
        ans.push_back(to_string(s[i] - 'a' + 1));
    }
    // for(auto el:ans)cout<<el<<" ";
    int res = 0;
    string str = "";
    for (int i = 0; i < ans.size(); i++)
    {
        // res+=stoi(ans[i]);
        str += ans[i];
    }
    cout<<str<<" ";
    while (k--)
    {
        res=0;
        for (int i = 0; i < str.size(); i++)
        {
            string temp = "";
            temp+=str[i];
            res += stoi(temp);
        }
        str = to_string(res);
    }
    return res;
}
int main(){
    string s = "leetcode";
    int k=2;
    cout<<getLucky(s,k)<<endl;
    // int res = stoi("1");
    // cout<<res<<endl;
}