#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <vector>
using namespace std;

int maximumTotalReward(vector<int> &rewardValues)
{
    int n = rewardValues.size();
    sort(rewardValues.begin(), rewardValues.end());
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int x = 0;
        for (int j = 0; j < n; j++)
        {
            if(i == j){
                continue;
            }
            if (rewardValues[j] > x)
            {
                x += rewardValues[j];
                cout<<x<<" ";
            }
        }
        ans = max(ans, x);
    }
    return ans;
}

int main()
{
    vector<int> rewards3 = {1,2,3,4,6};
    cout << "Result 2: " << maximumTotalReward(rewards3) << endl;

    return 0;
}