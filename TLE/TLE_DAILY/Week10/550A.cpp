#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void res(string str){
    
    ll n = str.length();
    int cnt = 0;
    int flag=0;
    for (int i = 0; i < n; i++)
    {
        if (flag==1 && (str[i] == 'B' && str[i + 1] == 'A'))
        {
            cout<<"YES"<<endl;
            return;
        }
        if (flag==0 && (str[i] == 'A' && str[i + 1] == 'B'))
        {
            flag=1;
            i++;
        }
    }
    flag=0;
    for (int i = 0; i < n; i++)
    {
        if (flag==1 && (str[i] == 'A' && str[i + 1] == 'B'))
        {
            cout<<"YES"<<endl;
            return;
        }
        if (flag==0 && (str[i] == 'B' && str[i + 1] == 'A'))
        {
            flag=1;
            i++;
        }
    }
    cout<<"NO"<<endl;
}
int main()
{
    string str;
    cin >> str;
    res(str);
}
