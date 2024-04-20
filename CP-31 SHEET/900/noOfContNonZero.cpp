#include <iostream>

int countNonZeroGroups(int arr[], int size) {
    int count = 0;
    bool inGroup = false;

    for (int i = 0; i < size; ++i) {
        if (arr[i] != 0 && !inGroup) {
            inGroup = true;
            count++;
        } else if (arr[i] == 0 && inGroup) {
            inGroup = false;
        }
    }

    return count;
}

int main() {
    int arr[] = {1000000};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = countNonZeroGroups(arr, size);
    std::cout << "Number of non-zero integer groups separated by zero: " << result << std::endl;
    return 0;
}
