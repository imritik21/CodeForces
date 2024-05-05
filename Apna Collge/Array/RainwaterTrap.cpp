#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    int n=6;
    int height[] = {4,2,0,3,2,5};
    int leftMaxBoundry[n],rightMaxBoundry[n];
    // calculate leftMaxBoundry
    leftMaxBoundry[0]=height[0];
    for(int i=1;i<n;i++){
        leftMaxBoundry[i]=max(leftMaxBoundry[i-1],height[i]);
    }
    //printLeftMax
    for(int i=0;i<n;i++){
        cout<<leftMaxBoundry[i]<<" ";
    }
    cout<<endl;
    // calculate rightMaxBoundry
    rightMaxBoundry[n-1]=height[n-1];
    for(int i=n-2;i>=0;i--){
        rightMaxBoundry[i]=max(rightMaxBoundry[i+1],height[i]);
    }
    //printRightMax
    for(int i=0;i<n;i++){
        cout<<rightMaxBoundry[i]<<" ";
    }
    cout<<endl;
    int TrappedWater=0;
    // calculate trapped water = (waterLevel- height)
    for(int i=0;i<n;i++){
        int waterLevel=min(leftMaxBoundry[i],rightMaxBoundry[i]);
        TrappedWater+=waterLevel-height[i];
    }
    cout<<TrappedWater<<endl;
}
