#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
// bool comp(int a,int b){
//     if(abs(a)<abs(b)){
//         return true;
//     }else{
//         return false;
//     }
//    return a<b;
// }
bool comp(pair<int,int>ab,pair<int,int>cd){
    // if(ab.first<cd.first){
    //     return true;
    // }
    // else if(ab.first>cd.first){
    //     return false;
    // }
    // else{
    //     if(ab.second<cd.second){
    //         return true;
    //     }
    //     else{
    //         return false;
    //     }
    // }
    if(ab.first!=cd.first){
        return ab.first<cd.first;
    }
    return ab.second<cd.second;
}
int main(){
    // lets say we need to sort it according to its absolute value
    // so we'll need the use of comparator
    int a[5]={1,2,-1,-2,3};
    // sort(a,a+5);
    // sort(a,a+5,comp);
    // for(auto it: a){
    //     cout<<it<<" ";
    // }


    pair<int,int> arr[5]={
        {1,2},
        {2,4},
        {1,3},
        {1,5},
        {3,2}
    };
    sort(arr,arr+5);
    for(auto it: arr){
        cout<<it.first<<" "<<it.second<<endl;;
    }
    cout<<endl;
}
