#include <bits/stdc++.h>
using namespace std;

string twoSum(int n, int arr[], int target) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) return "YES";
        }
    }
    return "NO";
}

int main()
{
    int n ,k;
	cin>>n>>k;
    int arr[n] ;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
    string ans = twoSum(n, arr, k);
    cout<< ans << endl;
    return 0;
}