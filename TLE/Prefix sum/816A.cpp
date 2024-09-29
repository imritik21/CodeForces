#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool isPalindrome(string s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;
    string hr = "";
    hr += str[0];
    hr += str[1];
    string min = "";
    min += str[3];
    min += str[4];
    string tot = hr + min;
    // cout<<tot<<endl;
    int cnt = 0;
    while (true)
    {
        string tot = hr + min;
        if (isPalindrome(tot))
        {
            break;
        }

        if (min == "59")
        {
            min = "00";
            if (hr == "23")
            {
                hr = "00";
            }
            else
            {
                int num = stoi(hr);
                num++;
                hr = to_string(num);
                if (num < 10)
                {
                    hr = '0' + hr;
                }
            }
        }
        else
        {
            int num = stoi(min);
            num++;

            min = to_string(num);
            if (num < 10)
            {
                min = '0' + min;
            }
        }
        // cout << hr << " " << min << endl;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
