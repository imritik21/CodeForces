#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main()
{
    int x,y;cin>>x>>y;
    // cout<<(x^x)<<endl;
    cout<<"initialy"<<"x= "<<x<<"and y= "<<y<<endl;
    x=x^y;
    y=x^y;
    x=x^y;
    cout<<x<<" "<<y;
}
