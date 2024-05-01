#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void printBin(int n,int lastplace,string& res){
    // base case
    if(n==0){
        cout<<res<<endl;
        return;
    }
    // kaam
    if(lastplace==0){
        printBin(n-1,0,res+="0");
        printBin(n-1,1,res+="1");
    }
    else{
        printBin(n-1,0,res+="0");
    }
}
int main(){
    int n;
    cin>>n;
    string res="";
    printBin(n,0,res);
}
