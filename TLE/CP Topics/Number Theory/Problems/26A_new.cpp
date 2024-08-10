#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const int N = 1e7;
int spf[N+1];
void solvespf()
{
    for(int i=0;i<N;i++){
        spf[i]=i; // initially
    }
    for(int i=2;i*i<N;i++){
        if(spf[i]==i){
            for(int j=i*i;j<N;j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
}
int main(){
    int n;cin>>n;
    set<int> st;
    int cnt=0;
    solvespf();
    for(int i=2;i<=n;i++){
        int temp = i;
        while(temp>1){
            st.insert(spf[temp]);
            temp/=spf[temp];
        }
        if(st.size()==2){ // count unique 2 prime fac of each i btw 1 to n
            cnt++;
            st.clear();
        }
        st.clear();
    }
    cout<<cnt<<endl;
}
