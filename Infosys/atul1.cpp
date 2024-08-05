#include <iostream>
#include <vector>
#include <limits.h> // For INT_MIN

using namespace std;

int maxTriple(vector<int> &A, int n) {
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

    // Traverse the array to find max1, max2, and max3
    for (int i = 0; i < n; ++i) {
        if (A[i] > max1) {
            max3 = max2; // Update third max to be second max
            max2 = max1; // Update second max to be first max
            max1 = A[i]; // Update first max to current element
        } else if (A[i] > max2 && A[i] != max1) {
            max3 = max2; // Update third max to be second max
            max2 = A[i]; // Update second max to current element
        } else if (A[i] > max3 && A[i] != max2 && A[i] != max1) {
            max3 = A[i]; // Update third max to current element
        }
    }

    // Handle the case where there are fewer than 3 unique values
    if (max3 == INT_MIN) {
        return (max1 + max2); // Return the sum of the top two if less than 3 unique values
    }

    return (max1 + max2 + max3); // Return the sum of the top three
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N);

    // Read the array elements
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    cout << maxTriple(A, N) << endl;

    return 0;
}
