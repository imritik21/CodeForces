#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    int A[n];
    int B[n];
    for(int i=1;i<=n;i++){
        cin>>A[i];
    }
    for(int i=1;i<=n;i++){
        cin>>B[i];
    }
    ll sum=0;
    for(int i=1;i<=n;i++){
        ll sum1=0;
        if(x>=0 && y>=0 && z>=0 ){
            //operation 1
            sum1=sum1-B[i];
        }
        ll sum2=0;
        ll oper2=1;
        if(x>=0 && y>=0 && z>=0 ){
            //operation 2
            x--;y--;
            oper2=oper2*A[i];
            oper2=oper2*x;
            oper2=oper2*y;
            oper2=oper2*z;
            sum2=sum2+oper2;
        }
        ll sum3=0;
        ll oper3=1;
        if(x>=0 && y>=0 && z>=0 ){
            //operation 1
            z--;y--;
            oper3=oper3*A[i];
            oper3=oper3*x;
            oper3=oper3*y;
            oper3=oper3*z;
            sum3=sum3+oper3;
        }
        sum=sum+max(sum1,max(sum2,sum3));
    }
    cout<<sum<<endl;
}
