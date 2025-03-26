#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    int n;
    cin>>n;
    vector<int> v;
    int i=1,j=2;
    while(j<=n){
        v.push_back(j);
        j+=2;
    }
    while(i<=n){
        v.push_back(i);
        i+=2;
    }
    if(n<=3 && n!=1){
        cout<<"NO SOLUTION"<<endl;
    }
    else if(n==1){
        cout<<1<<endl;
    }
    else{
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}
