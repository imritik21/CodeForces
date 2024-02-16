#include <iostream>
#include <vector>

using namespace std;

const int mod = 998244353;

int count_rearrangements(int N, vector<int>& A) {
    int ones_count = 0;
    int neg_ones_count = 0;

    for (int num : A) {
        if (num == 1) {
            ones_count++;
        } else {
            neg_ones_count++;
        }
    }

    int result = (static_cast<long long>(ones_count) * neg_ones_count) % mod;
    return result;
}

int main() {
    int N = 5;
    vector<int> A = {1, -1, -1, -1, -1};
    int result = count_rearrangements(N, A);
    cout << result << endl;

    return 0;
}