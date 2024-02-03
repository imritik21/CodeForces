#include <iostream>
using namespace std;
int main(){
    int N,S,K;
    cin>>N;
    cin>>S;
    cin>>K;
    int total=0;
    int p[N],q[N];
    for (int i = 1; i <=N; i++)
    {
        cin>>p[i]>>q[i];
    }
    for (int i = 1; i <=N; i++)
    {
        total=total+p[i]*q[i];
    }
    if (total<S)
    {
        total=total+K;
    }
    cout<<total;
}