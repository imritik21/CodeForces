#include <bits/stdc++.h>
#include <string>
using namespace std;


int countGoodIndices(int n,string& s) {
    // int n = s.length();
    int goodCount = 0;

    for (int i = 0; i <= n - 2; ++i) {
        int countAFirstPart = std::count(s.begin(), s.begin() + i + 1, 'a');
        int countASecondPart = std::count(s.begin() + i + 1, s.end(), 'a');

        if (countAFirstPart == countASecondPart) {
            ++goodCount;
        }
    }

    return goodCount;
}

int main() {
    // std::string inputString;
    // std::cout << "Enter the string 'S': ";
    // std::cin >> inputString;

    // int result = countGoodIndices(inputString);

    // std::cout << "Total number of 'good' indices: " << result << std::endl;

    int result=countGoodIndices()
    return 0;
}