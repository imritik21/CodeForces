#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int x[n];
    for (int i = 0; i < n; i++)
    {
        cin>>x[i];
        
    }
    bool found=false;
    for (int i = 0; i < n; i++)
    {
        if(x[i]==1){
        found=true;
        break;
        }
    }
    if(found){
    cout<<"HARD";
    }
    else
    cout<<"EASY";
}