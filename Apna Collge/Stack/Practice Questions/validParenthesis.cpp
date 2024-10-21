#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool isValid(string str)
{
    int n = str.size();
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        char ch = str[i];

        if (ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }

            // check if pair form ho rha hai
            if ((st.top() == '(' && ch == ')') || (st.top() == '[' && ch == ']') ||
                (st.top() == '{' && ch == '}'))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }

    if (st.empty())
        return true;
    else
        return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str = "(){}[]";
    cout << isValid(str) << endl;
    return 0;
}
