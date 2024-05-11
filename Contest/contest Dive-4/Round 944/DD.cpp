#include <iostream>
#include <string>
#include <algorithm>

int minPiecesToSortBinaryString(const std::string& binaryString) {
    int count0 = std::count(binaryString.begin(), binaryString.end(), '0');
    int count1 = binaryString.size() - count0;
    
    return std::min(count0, count1);
}

int main() {
    std::string binaryString;
    std::cout << "Enter the binary string: ";
    std::cin >> binaryString;
    
    int minPieces = minPiecesToSortBinaryString(binaryString);
    std::cout << "Minimum number of pieces needed: " << minPieces << std::endl;
    
    return 0;
}
