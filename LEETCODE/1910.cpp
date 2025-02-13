#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
string removeOccurrences(string s, string part)
{
    string ans = "";
    stack<char> st;
    ///   dbc       abc
    for (int i = 0; i < s.size(); i++)
    {
        st.push(s[i]);
        int j = part.size() - 1;
        string curr = "";
        while (!st.empty() && st.top() == part[j] && j >= 0)
        {
            curr += st.top();
            st.pop();
            j--;
        }
        reverse(curr.begin(), curr.end());
        if (curr == part)
            continue;
        else
        {
            for (int k = 0; k < curr.size(); k++)
            {
                st.push(curr[k]);
            }
        }
    }
    if (st.empty())
        return "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s ="dabcdcabcc";
    string part ="abc";
    cout<<removeOccurrences(s,part)<<endl;
    return 0;
}
