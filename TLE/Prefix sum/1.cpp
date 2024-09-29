#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string a,b;
        cin>>a;
        cin>>b;
        int mf=0,mb=0;
        // int n = a.size();
        for(int i=0;i<n;i++)
        {
            if(a[i]!=b[i])mf++;
            if(a[i]!=b[n-1-i])mb++;
        }
        // cout<<mf<<' '<<mb<<'\n';
        int movef=2*mf-(mf%2);
        int moveb=2*mb-(1-(mb%2));
        if(moveb==-1)moveb=2;
        cout<<min(movef,moveb)<<'\n';
    }
    return 0;
}