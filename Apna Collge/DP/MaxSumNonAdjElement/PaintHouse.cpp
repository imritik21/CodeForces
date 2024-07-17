#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
long long int distinctColoring(int N, int r[], int g[], int b[]){
        // code here 
        long long red=r[0];
        long long green=g[0];
        long long blue=b[0];
        for(int i=1;i<N;i++){
            long long nred = r[i]+min(green,blue);
            long long nblue = b[i]+min(red,green);
            long long ngreen = g[i]+min(red,blue);
            
            red = nred;
            blue=nblue;
            green=ngreen;
        }
        return min({red,blue,green});
    }
int main()
{
    int N = 3;
    int r[]={1,1,1};
    int g[]={2,2,2};
    int b[]={3,3,3};
    cout<<distinctColoring(N,r,g,b)<<endl;
    return 0;
}
