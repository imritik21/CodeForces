#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
/*
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> nums = {9,7,7,9,7,7,9};
    int k = 7;
    // initially take from start
    int n = nums.size();
    int leftSum=0;
    for(int i=0;i<k;i++){
        leftSum+=nums[i];
    }
    // ab yha se ghatao peeche se add kro
    int lastInd=n-1;
    int maxPoints=0;
    for(int i=k-1;i>=0;i--){
        leftSum-=nums[i];
        leftSum+=nums[lastInd];
        maxPoints=max(maxPoints,leftSum);
        lastInd--;
    }
    cout<<maxPoints<<endl;
    return 0;
}
