#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    int n;cin>>n;
    unordered_map<int,int> mpp;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    for(int i=0;i<n;i++){
        if(vec[i]%2==0){
            mpp[vec[i]]++;
        }
    }
    for(int i=0;i<n;i++){
        if(mpp[vec[i]]==0){
            cout<<vec[i]<<endl;
        }
    }
}
