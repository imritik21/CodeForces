#include <iostream>
#include <string>

std::string generateString(int n) {
    if (n % 2 == 1 || n < 2) {
        std::cout << "NO" << std::endl;
        return "";
    }

    std::string result = "YES\n";
    for (int i = 0; i < n / 2; ++i) {
        result += "AAB";
    }

    return result;
}

int main() {
    int t; // Number of test cases
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::string result = generateString(n);
        if (!result.empty()) {
            std::cout << result << std::endl;
        }
    }

    return 0;
}
