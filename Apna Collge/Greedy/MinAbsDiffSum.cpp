#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a[] = {4,1,8,7};
    int b[] = {2,3,6,5};
    sort(a,a+4);
    sort(b,b+4);
    int maxDiffSum=0;
    for(int i=0;i<4;i++){
        maxDiffSum+=abs(a[i]-b[i]);
    }
    cout<<maxDiffSum<<endl;
}
