/*Memo and Momo are playing a game. Memo will choose a positive number a
, and Momo will choose a positive number b
.

Your task is to tell them who will win according to the following rules:

If both a and b are divisible by k, both of them win and you should print "Both".
If a is divisible by k but b isn't, Memo wins and you should print "Memo".
If b is divisible by k but a isn't, Momo wins and you should print "Momo".
If both a and b are not divisible by k , no one wins and you should print "No One".
Input
Only one line containing three positive numbers a, b and k (1≤a,b,k≤10^18)*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int a,b,k;
    cin>>a>>b>>k;
    if(a%k==0 && b%k==0){
        cout<<"Both";
    }
    else if(a%k==0){
        cout<<"Memo";
    }
    else if(b%k==0){
        cout<<"Momo";
    }
    else
    cout<<"No One";
}