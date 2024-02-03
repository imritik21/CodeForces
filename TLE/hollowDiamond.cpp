#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter row: ";
    cin>>n;
    cout<<"Enter col: ";
    cin>>m;
    for(int i=0;i<n-1;i++){
        cout<<" ";
    }
    cout<<"*"<<endl;
    // printing double stars;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-2;j++)
            cout<<" ";
        cout<<"*";
        // printing space in middle
        for(int k=0;k<2*i+1;k++)
            cout<<" ";
        cout<<"* "<<endl;
    }
    // for printing double stars [n-2, 0]
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<n-i-2;j++)
            cout<<" ";
        cout<<"*";
        // printing space in middle
        for(int k=0;k<2*i+1;k++)
            cout<<" ";
        cout<<"* "<<endl;
    }
    for(int i=0;i<n-1;i++)
        cout<<" ";
    cout<<"*"<<endl;
}