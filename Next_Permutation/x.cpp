#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
    long long pts = 0;
    sort(enemyEnergies.begin(), enemyEnergies.end()); // Sort energies in ascending order
    int n = enemyEnergies.size();
    int l = 0, r = n - 1;

    while (l <= r) {
        // Check if current energy is sufficient to defeat the weakest remaining enemy
        if (currentEnergy >= enemyEnergies[l]) {
            currentEnergy -= enemyEnergies[l];
            pts++;
        } else if (pts > 0) { // Use points to regain energy from the strongest defeated enemy
            currentEnergy += enemyEnergies[r];
            r--;
        } else {
            break; // Neither enough energy to defeat an enemy nor points to regain energy
        }
    }

    return pts;
}

int main() {
    vector<int> enemyEnergies = {2}; // Example input
    int currentEnergy = 10;
    cout << maximumPoints(enemyEnergies, currentEnergy) << endl; // Output the maximum points
    return 0;
}
