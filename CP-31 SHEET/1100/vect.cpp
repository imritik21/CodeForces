#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> arr = {1,29,3,4,5,6};
    cout<<arr.front()<<endl;
    vector<int>::iterator it = arr.begin();
    cout << *it << endl;
    
    ++it;
    cout << *it << endl;

    vector<int>::iterator it1 = arr.end();
    cout << *--it1 << endl;
    
    // Move iterator to the second element
    it1--;
    cout << *it1 << endl;


    arr.erase(arr.begin()+0);
    arr.erase(arr.end()-1);
    for(auto it:arr)cout<<it<<" ";
    return 0;
}
