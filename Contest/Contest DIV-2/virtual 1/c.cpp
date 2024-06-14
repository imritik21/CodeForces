#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isSameFrequency(const vector<int>& a, const vector<int>& b) {
    unordered_map<int, int> freqA, freqB;

    // Calculate the frequency of each element in both arrays
    for (int num : a) {
        freqA[num]++;
    }

    for (int num : b) {
        freqB[num]++;
    }

    // Compare the frequency maps
    return freqA == freqB;
}

int canYouMakeEqual(int n, vector<int>& a, vector<int>& b) {
    if (isSameFrequency(a, b)) {
        return 1; // Arrays can be made identical by swapping
    }
    return 0; // Arrays cannot be made identical
}

int main() {
    vector<int> a = {3, 1, 2, 2, 1, 4};
    vector<int> b = {1, 2, 1, 1, 5, 1};
    int n = a.size();
    
    cout << "Can you make the arrays equal: " << canYouMakeEqual(n, a, b) << endl;
    return 0;
}
