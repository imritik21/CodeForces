#include <bits/stdc++.h>
using namespace std;
int if1=0,if2=0;
// long long maximumPoints(vector<int> &enemyEnergies, int currentEnergy)
// {
//     long long pts = 0;
//     int mini = *min_element(enemyEnergies.begin(), enemyEnergies.end());
//     sort(enemyEnergies.begin(), enemyEnergies.end());
//     int n = enemyEnergies.size();
//     vector<int> marked(n, 0);
//     int r = n - 1;
    
//     while (r != -1)
//     {
//         if (currentEnergy >= mini)
//         {
//             if1++;
//             currentEnergy -= mini;
//             pts++;
//             cout<<"if1 "<<currentEnergy<<" "<<pts<<endl;
//         }
//         else if (currentEnergy < mini && pts > 0)
//         {
//             if2++;
//             currentEnergy += enemyEnergies[r];
//             r--;
//             cout<<r<<endl;
//             cout<<"if2 "<<currentEnergy<<" "<<pts<<endl;
//         }
//     }
//     return pts;
// }
long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
    sort(enemyEnergies.begin(), enemyEnergies.end());
    
    long long pts = 0;
    
    for (int energy : enemyEnergies) {
        if (currentEnergy >= energy) {
            currentEnergy -= energy;
            pts++;
        } else {
            break; // No need to continue if we can't defeat this enemy
        }
    }
    
    return pts;
}
int main(){
    vector<int> enemyEnergies = {2,2,3};
    int currentEnergy = 2;
    cout<<maximumPoints(enemyEnergies,currentEnergy)<<endl;
    // cout<<if1<<" "<<if2;
}