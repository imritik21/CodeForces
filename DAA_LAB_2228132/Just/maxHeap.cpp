#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void insert(vector<int> &arr, int n)
{
    int i = n;
    int temp = arr[n];

    while(i>1 && temp>arr[i/2]){
        arr[i]=arr[i/2];
        i/=2;
    }
    arr[i]=temp;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr =
        return 0;
}
