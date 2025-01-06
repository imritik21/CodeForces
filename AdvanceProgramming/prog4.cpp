#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    std::ifstream inFile("example.txt");
    if (!inFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string word, firstWord, lastWord;
    bool isFirstWord = true;

    // Read all words from the file
    while (inFile >> word) {
        if (isFirstWord) {
            firstWord = word;  // Store the first word
            isFirstWord = false;
        }
        lastWord = word;  // Continuously update with the last word
    }

    inFile.close();

    // Display the results
    if (!firstWord.empty()) {
        std::cout << "First Word: " << firstWord << std::endl;
    } else {
        std::cout << "The file is empty." << std::endl;
    }

    if (!lastWord.empty()) {
        std::cout << "Last Word: " << lastWord << std::endl;
    }

    return 0;
}
