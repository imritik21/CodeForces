#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=1;i<=n;i++) cin>>arr[i];
    int i=1,j=n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(pow(arr[i],j)<=arr[j]){
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
}
int main() {
	// your code goes here
	int tc;
	cin>>tc;
	while(tc--){
	    solve();
	}
}
