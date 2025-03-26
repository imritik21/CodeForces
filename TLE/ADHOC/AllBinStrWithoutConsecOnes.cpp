#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void printBin(int n,int last,string str)
{
    if(n==0){
        cout<<str<<endl;
        return;
    }
    if(last==0){
        printBin(n-1,0,str+"0");
        printBin(n-1,1,str+"1");
    }
    else{
        printBin(n-1,0,str+"0");
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n=5;
    // string str = "";
    printBin(n,0," ");
    // cout<<str<<endl;
    return 0;
}
