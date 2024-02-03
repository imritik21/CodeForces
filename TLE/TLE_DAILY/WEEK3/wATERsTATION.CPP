#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n%5>2){
        cout<<(n-n%5)+5<<endl;
    }
    else
    cout<<(n-n%5)<<endl;
}