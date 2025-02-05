// approach:
//  well explore every nodes i.e [0....9999] and mark them with their updated
//  dist no need of pq as the dist inc normally
/*
3
3 4 65
7 66175

Given start, end and an array arr of n numbers. At each step,
start is multiplied with any number in the array and then mod operation
 with 100000 is done to get the new start.

Your task is to find the minimum steps in which end can be achieved starting
 from start. If it is not possible to reach end, then return -1.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e5;
int minimumMultiplications(vector<int>& arr,int start,int end){
    // consider every steps to be a node 
    vector<int> dist(1e5,1e9);
    dist[start]=0;// return the dist of end
    queue<pair<int,int>> q;
    q.push({0,start});// 0 steps
    while(!q.empty()){
        int step = q.front().first;
        int node = q.front().second;
        q.pop();

        if(node==end){
            return step;
        }

        // iterate through array using multiplied by this node value
        for(auto& ele:arr){
            int req = (ele*node)%mod;

            if(step+1<dist[req]){
                dist[req] = step+1;
                q.push({step+1,req});
            }
        }
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /*  3
        3 4 65
        7 66175   ans=4
    */

    vector<int> arr = {3,4,65};
    int start=7,end=66175; // ans = 2
    cout<<minimumMultiplications(arr,start,end)<<endl;
    return 0;
}
