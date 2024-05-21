#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
string reverseStr(string str)
{
    stack<char> st;
    int idx=0;
    while(idx<str.length()){
        st.push(str[idx]);
        idx++;
    }
    string res="";
    while(!st.empty()){
        char c = st.top();
        st.pop();
        res+=c;
    }
    return res;
}
int main()
{
    string str;
    cin >> str;
    cout << reverseStr(str);
}