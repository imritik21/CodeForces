#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int tiling(int n){
    if(n==0 || n==1){
        return 1;
    }
    // horizontal tile fun(n-2)
    // vertical tile fun(n-1)
    // add both we'll get the result
    return tiling(n-1)+tiling(n-2);

}
int main(){
    int n;
    cin>>n;
    cout<<tiling(n)<<endl;
}
