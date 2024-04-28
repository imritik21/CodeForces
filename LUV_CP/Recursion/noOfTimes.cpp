// write an infinite recursive function that prints
// the number of times it has run
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int fun(int n){
    if(n==0){
        return 1;
    }
    return fun(n-1)+1;
}
int main(){
    int n;
    cin>>n;
    cout<<fun(n);

}
