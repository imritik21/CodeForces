#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
vector<vector<int>> final_ans;
vector<int> curr;
void subset(int arr[],int n,int i){
    // base cond
    if(i==n){
        final_ans.push_back(curr);
        return;
    }
    subset(arr,n,i+1);
    curr.push_back(arr[i]);
    subset(arr,n,i+1);
    curr.pop_back();
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    subset(arr,n,0);
    for(int i=0;i<final_ans.size();i++){
        for(int j=0;j<final_ans[i].size();j++){
            cout<<final_ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
