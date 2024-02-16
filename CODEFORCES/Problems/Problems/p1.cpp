#include <bits/stdc++.h>
using namespace std;
// Given 4 numbers A,B,Cand D. If AB> CD print "YES" otherwise, print "NO".
int main(){
    double A,B,C,D;
    cin>>A>>B>>C>>D;
    double x=log(A);
    double y=log(C);
    if (x*B>y*D)
    {
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}