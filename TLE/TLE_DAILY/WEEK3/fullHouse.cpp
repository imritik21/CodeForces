#include<bits/stdc++.h>
using namespace std;
int main(){
    // int a,b,c,d,e;
    // cin>>a>>b>>c>>d>>e;
    int A[14];
    for(int i=0;i<14;i++){
        A[i]=0;
    }
    for(int i=0;i<5;i++){
        int n;
        cin>>n;
        A[n]++;
    }
    bool cnt1=0,cnt2=0;
    for(int i=0;i<14;i++){
        if(A[i]==2){
            cnt1=1;
        }
        if(A[i]==3){
            cnt2=1;
        }
    }
    if(cnt1==1 && cnt2==1){
        cout<<"Yes"<<endl;
    }
    else
    cout<<"No"<<endl;
}