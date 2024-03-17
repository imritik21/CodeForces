#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    int y,w;
    cin>>y>>w;
    int x=max(y,w);
    int res=6-x+1;
    if(res==0){
        cout<<"0/1";
    }
    else if(res==1){
        cout<<"1/6";
    }
    else if(res==2){
        cout<<"1/3";
    }
    else if(res==3){
        cout<<"1/2";
    }
    else if(res==4){
        cout<<"2/3";
    }
    else if(res==5){
        cout<<"5/6";
    }
    else if(res==6){
        cout<<"1/1";
    }
}
