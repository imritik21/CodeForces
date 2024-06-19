#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        v.push_back(i);
    }
    cout<<v.size()<<endl;
    do{
        for(auto el: v){
            cout<<el<<" ";
        }
        cout<<endl;
    }
    while(next_permutation(v.begin(),v.end()));
}
