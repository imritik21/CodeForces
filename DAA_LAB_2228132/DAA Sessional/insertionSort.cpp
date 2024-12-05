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
    

    vector<int> arr = {2,3,4,5,1,6,2,9};
    int n = arr.size();

    for(int i=1;i<n;i++){
        int curr = arr[i];
        int j=i-1;
        while(j>=0 && curr<arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=curr;
    }
    for(auto ele:arr){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
