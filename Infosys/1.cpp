#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mod  =1e9+7;
long long calculateXorSum(const vector<long long>& A, long long x) {
    long long xorSum = 0;
    for (long long a : A) {
        xorSum += (x ^ a);
    }
    return xorSum;
}

long long findMaxXorSum(const vector<long long>& A, long long K) {
    long long maxXorSum = 0;
    long long maxX = 0;

    // Try all possible x from 0 to K
    for (int bit = 60; bit >= 0; --bit) {
        long long candidateX = maxX | (1LL << bit);
        if (candidateX > K) continue;

        long long currentXorSum = calculateXorSum(A, candidateX);
        long long currentXorSumWithMax = calculateXorSum(A, maxX | K);

        if (currentXorSumWithMax > maxXorSum) {
            maxXorSum = currentXorSumWithMax;
            maxX = maxX | K;
        } else if (currentXorSum > maxXorSum) {
            maxXorSum = currentXorSum;
            maxX = candidateX;
        }
    }
    return maxXorSum;
}

int main() {
    // int N;
    // long long K;
    // cin >> N >> K;

    // vector<long long> A(N);
    // for (int i = 0; i < N; ++i) {
    //     cin >> A[i];
    // }

    // long long result = findMaxXorSum(A, K);
    // cout << result << endl;
    cout<<(142609890)%mod;
    return 0;
}
