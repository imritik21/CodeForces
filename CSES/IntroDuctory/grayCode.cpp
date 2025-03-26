#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
// void backtrack(int n, string bit)
// {
//     if(bit.size()==n){
//         cout<<bit<<endl;
//         return;
//     }
//     backtrack(n, bit + "0");
//     backtrack(n, bit + "1");
// }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    int n;
    cin>>n;
    vector<string> gray;
    gray.push_back("0");
    gray.push_back("1");

    for(int i=2;i<=n;i++){
        int size = gray.size();

        // reverse of prev add in new 
        for(int j=size-1;j>=0;j--){
            gray.push_back(gray[j]);
        }
        // now add 0 to start and reverse wale me 1
        for(int j=0;j<size;j++){
            gray[j] = "0"+gray[j];
            gray[j+size] = "1"+gray[j+size];
        }
    }
    for(auto& it:gray)cout<<it<<endl;
    return 0;
}
