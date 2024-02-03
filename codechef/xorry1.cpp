#include <iostream>

std::pair<int, int> findXORPair(int n) {
    int a = 0;
    int b = n;

    // Find the rightmost set bit in n
    int mask = 1;
    while ((n & mask) == 0 && mask <= n) {
        mask <<= 1;
    }

    // If mask is less than n, set the rightmost bit in a
    if (mask < n) {
        a ^= mask;
    }

    return std::make_pair(a, b);
}

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    std::pair<int, int> xorPair = findXORPair(num);

    std::cout << "XOR Pair: (" << xorPair.first << ", " << xorPair.second << ")\n";

    return 0;
}
