#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool checkPowersOfThree(int n)
{
    // greedily choose the highest power and descend
    bool flag = false;
    for (int bit = 19; bit >= 0; bit--)
    {
        int curr = pow(3,bit);
        
        if (curr <= n)
        {
            cout<<curr<<endl;
            n -= curr;
        }
    }
    if (n == 0)
        return true;
    else
        return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    if(checkPowersOfThree(n))cout<<"TRUE"<<endl;
    else cout<<"FALSE"<<endl;
    return 0;
}
