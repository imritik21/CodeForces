#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void towerOfHanoi(int n, int a, int b, int c)
{
    if(n==0)return;
    towerOfHanoi(n-1,a,c,b);
    cout<<a<<" "<<c<<endl;
    towerOfHanoi(n-1,b,a,c);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    cout << (1 << n) - 1 << endl;
    towerOfHanoi(n, 1, 2, 3);
    return 0;
}
