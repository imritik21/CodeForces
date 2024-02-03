#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> originalVector = {1, 2, 3, 5, 4, 5, 6, 7, 9};

    int maxLength = 0;
    int currentLength = 1;

    for (size_t i = 0; i < originalVector.size() - 1; ++i) {
        if (std::abs(originalVector[i + 1] - originalVector[i]) == 1) {
            // If the difference is 1 or -1, increase the current length
            currentLength++;
        } else {
            // If the difference is not 1 or -1, update the maximum length
            maxLength = std::max(maxLength, currentLength);
            // Reset the current length for the next subarray
            currentLength = 1;
        }
    }

    // Update the maximum length after the loop in case the last elements form a subarray
    maxLength = std::max(maxLength, currentLength);

    std::cout << "Maximum Length of Subarray: " << maxLength << std::endl;

    return 0;
}
