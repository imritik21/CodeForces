#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
// 0 1 1 2 3 5 8 13 21
// 1 2 3 4 5 6 7 8  9
vector<int> res;
void nthFib(int n){
    if(n==0 || n==1){
        res.push_back(n);
        return;
    }

    
}
int main(){
    int n;
    cin>>n;
    cout<<nthFib(n)<<endl;
}
