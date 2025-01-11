#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void subset(int idx,int n,vector<int>&arr,
            vector<int>&temp,int &maxi){
    if(idx==n){
        // if(temp.size()<4){
        //     for(int i=0;i<temp.size();i++){
        //         maxi=max(maxi,temp[i]);
        //     }
        // }
        // else {
            int val=0;
            for(int j=0;j<temp.size();j++){
                if(j==0){
                    val=temp[0];
                }
                else{
                    if(j%3==1){
                        val = val|temp[j];
                    }
                    else if(j%3==2){
                        val = val ^ temp[j];
                    }
                    else if(j%3==0){
                        val+=temp[j];
                    }
                }
            }
            maxi=max(maxi,val);
        // }
        return;
    }
    subset(idx+1,n,arr,temp,maxi);
    temp.push_back(arr[idx]);
    subset(idx+1,n,arr,temp,maxi);
    temp.pop_back();
}
void solve()
{
    string str;
    cin>>str;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)cin>>i;
    vector<int> temp;
    int maxi=-1;
    subset(0,n,arr,temp,maxi);
    // cout<<maxi<<endl;
    string res="";
    if(maxi%2==0){
        res="Even";
    }
    else{
        res="Odd";
    }
    // cout<<maxi<<endl;
    if(str==res)cout<<"Monk"<<endl;
    else cout<<"Mariam"<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}
