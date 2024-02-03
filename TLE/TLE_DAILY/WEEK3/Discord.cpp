/*https://atcoder.jp/contests/abc303/tasks/abc303_b*/

/*Constraints
  2≤N≤501≤M≤501≤ai,j≤Nai,1,…,ai,N
  contain each of1,…,N exactly once.All values in the input are integers.*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main()
{
    int n; // no of people
    int m; // no of photos
    cin >> n >> m;
    int arr[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            arr[i][j]--;
        }
    }
    // 4 2
    // 1 2 3 4 
    // 4 3 1 2 
    int count=0;
    for (int i = 0; i < n; i++)
    {
        int v[n];
        memset(v,0,sizeof(v)); // set 0 
        v[i]=1; // ith person can't be in bad mood;
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                if(arr[j][k]==i){
                    if(k>0 && k<n-1){
                        v[arr[j][k-1]]=1;
                        v[arr[j][k+1]]=1;
                    }
                    else if(k<n-1){
                        v[arr[j][k+1]]=1;
                    }
                    else if(k>0){
                        v[arr[j][k-1]]=1;
                    }
                }
            }
        }
    for (int i = 0; i < n; i++)
    {
        if(v[i]==0){count++;}
    }
    }
    cout<<count/2<<endl;
}