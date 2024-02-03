#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;

    long long prev2=0;
    long long prev1=1;
    if(n==1){
        cout<<prev2<<endl;
        return 0;
    }
    for(int i=3;i<=n;i++){
        long long num=prev1+prev2;
        prev2=prev1;
        prev1=num;
    }
    cout<<prev1<<endl;
}