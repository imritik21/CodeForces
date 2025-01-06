#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
class Data
{
public:
    int start, end;
    Data(int start, int end)
    {
        this->start=start;
        this->end=end;
    }
};
bool comp(Data val1,Data val2){
    return val1.end<val2.end;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> start(n), end(n);
    for (int i = 0; i < n; i++)
    {
        cin >> start[i] >> end[i];
    }

    vector<Data> arr;
    for(int i=0;i<n;i++){
        arr.push_back(Data(start[i],end[i]));
    }
    sort(arr.begin(),arr.end(),comp);
    int cnt=1,free=arr[0].end;
    for(int i=1;i<n;i++){
        if(arr[i].start>=free){
            cnt++;
            free=arr[i].end;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
