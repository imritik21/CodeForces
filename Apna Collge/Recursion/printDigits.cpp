#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void printDigits(ll n)
{

    if (n == 0)
    {
        return;
    }
    printDigits(n / 10);
    cout << n % 10 << " ";
}
int main()
{

    int tc;
    cin >> tc;
    while (tc--)
    {
        ll n;
        cin >> n;
        if(n==0){
            cout<<0<<endl;
        }
        else
        printDigits(n);
        cout<<endl;
    }
}