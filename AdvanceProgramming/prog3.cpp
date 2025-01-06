#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream sourceFile("source.txt");
    std::ofstream destinationFile("destination.txt", std::ios::app); // Open in append mode

    if (!sourceFile.is_open() || !destinationFile.is_open()) {
        std::cerr << "Error opening files!" << std::endl;
        return 1;
    }

    std::string line;
    while (getline(sourceFile, line)) {
        destinationFile << line << "\n";
    }

    std::cout << "Content appended successfully!" << std::endl;

    sourceFile.close();
    destinationFile.close();

    return 0;
}
