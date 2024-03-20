#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int q;cin>>q;
    while(q--){
        int k;cin>>k;
        auto lb_it=lower_bound(v.begin(),v.end(),k);
        int lb_index= lb_it-v.begin();
        bool isPresent=binary_search(v.begin(), v.end(),k);
        if(isPresent){
            cout<<"Yes"<<" "<<lb_index<<endl;
        }
        else cout<<"No"<<" "<<lb_index<<endl;
    }
    return 0;
}
