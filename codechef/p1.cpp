#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int tc;
	cin>>tc;
	while(tc--){
	    int n,k;
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int minn=INT_MAX;
	    int rem;
	    for(int i=0;i<n;i++){
	        if(k>=arr[i]){
	            rem=arr[i]-k*(arr[i]/k);
	            minn=min(minn,rem);
	        }
	        else{
	            return -1;
	        }
	    }
	    return minn;
	}
}
