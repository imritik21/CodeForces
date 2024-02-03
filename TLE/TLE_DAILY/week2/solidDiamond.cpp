#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        // print spce
        for(int j=0;j<n-i-1;j++)
        cout<<" ";
        // stars
        for(int j=0;j<i+1;j++)
        cout<<"* ";
        cout<<endl;
        // mirror
    }
    for(int i=n-1;i>=0;i--){
       for(int j=0;j<i+1;j++)
        cout<<"* ";
        cout<<endl;

        for(int j=0;j<n-i-1;j++)
        cout<<" ";
    }
}