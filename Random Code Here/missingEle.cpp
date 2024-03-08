#include <iostream>
#include <vector>
// missing ele natural numbers
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    int total = (n * (n + 1)) / 2;
    int sum = 0;

    cout << "Enter " << n-1 << " elements of the array (consecutive integers): ";
    for (int i = 0; i < n-1; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    cout << "The missing element is: " << total - sum << endl;

    return 0;
}
