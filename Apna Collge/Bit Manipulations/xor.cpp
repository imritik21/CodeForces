#include <iostream>

int main() {
    int arr[] = {1,3}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    int xorSum = 0;
    for(int i = 0; i < n; i++) {
        xorSum ^= arr[i];
    }

    std::cout << "XOR of all elements in the array is: " << xorSum << std::endl;

    return 0;
}
