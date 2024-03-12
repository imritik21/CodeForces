#include <iostream>

int minimumSocksToRemove(int numColors) {
    // The minimum number of socks to ensure a matching pair is three
    return 2 * (numColors - 1) + 1;
}

int main() {
    int numColors;
    std::cout << "Enter the number of colors of socks in the drawer: ";
    std::cin >> numColors;

    int minSocksToRemove = minimumSocksToRemove(numColors);

    std::cout << "The minimum number of socks to ensure a matching pair is: " << minSocksToRemove << std::endl;

    return 0;
}
