#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

    int diff = arr[0] - 0;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] - i != diff) {
            while (diff < arr[i] - i) {
                cout << "Missing element: " << diff + i << endl;
                diff++;
            }
        }
    }

    // Handle the case where the missing element is at the end of the array
    if (diff + n - 1 != arr[n - 2]) {
        cout << "Missing element: " << diff + n - 1 << endl;
    }

    return 0;
}
