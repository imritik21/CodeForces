//Given two numbers N and M. Print the summation of their last digits.
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long N,M;
    cin>>N>>M;
    long long res1=N%10 +M%10;
    cout<<res1;
}