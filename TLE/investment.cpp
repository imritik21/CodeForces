#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long maximumRupees(int n, int x, vector<int> &a) {
    sort(a.rbegin(), a.rend()); // Sort stocks in descending order of value

    long long rupees = x;
    for (int i = 0; i < n; ++i) {
        if (rupees >= a[i]) {
            // Buy as many stocks as possible
            long long stocksBought = rupees / a[i];
            rupees -= stocksBought * a[i];
        }
    }
    return rupees;
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long result = maximumRupees(n, x, a);

    cout << "Maximum rupees after buying stocks: " << result << endl;

    return 0;
}
