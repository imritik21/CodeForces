#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int n;
void rec(string str){
    if(str.length()==n){
        cout<<str<<endl;
        return;
    }
    rec(str+'0');
    rec(str+'1');
}
int main(){
    // int n;
    cin>>n;
    rec("");
}
