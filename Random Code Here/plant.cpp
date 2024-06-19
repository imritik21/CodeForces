#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,c;
    cin>>n>>c;
    vector<int> plants = {1,1,1,4,2,3};
    int steps=0;
    int req=c;
    for(int i=0;i<n;i++){
        if(plants[i]-req > 0){
            steps+=i;
            req=c;
            req-=plants[i];
        }
        else{
            steps++;
            req-=plants[i];
        }
    }
    cout<<steps*2<<endl;
}
