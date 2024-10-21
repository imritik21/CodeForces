#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, s;
    cin >> n >> s;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<pair<ll,ll>> p;
    for(int i=0;i<n;i++){
        p.push_back({arr[i],i});
    }
    sort(p.begin(), p.end());
    vector<int> ans;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        // if (i > 0 && arr[i] == arr[i - 1])
        //     i++;
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            // ll sum = arr[j] + arr[k];
            // sum += arr[i];
            ll sum = p[i].first+p[j].first;
            sum+=p[k].first;

            if (sum < s)
            {
                j++;
            }
            else if (sum > s)
            {
                k--;
            }
            else
            {
                if (flag == false)
                {
                    ans.push_back(p[i].second+1);
                    ans.push_back(p[j].second+1);
                    ans.push_back(p[k].second+1);
                }
                flag = true;
                j++;
                k--;
            }
        }
    }

    if(flag){
        sort(ans.begin(),ans.end());
        for(auto ele:ans)cout<<ele<<" ";
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}
