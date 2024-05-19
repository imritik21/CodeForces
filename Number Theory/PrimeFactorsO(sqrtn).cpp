#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main()
{
    int n;
    cin >> n;
    /*
    for eg=12
        1x12
        2x6
        3x4
        --- // now gets repeat so max you need to check is sqrt(n)
        4x3
        6x2
        12x1
    */
    vector<int> factors;
    // TC-O(sqrt(n));
    for (int i = 1; i * i <= n; i++)
    {
        if(n%i==0){
            factors.push_back(i);
            if(n/i != i){ // when n=16 4 would be pushed twice
                factors.push_back(n/i);
            }
        }
    }
    for(int i=0;i<factors.size();i++){
        cout<<factors[i]<<" ";
    }
}