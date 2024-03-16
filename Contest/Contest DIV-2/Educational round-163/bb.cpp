#include <iostream>
#include <vector>

std::string can_sort(int n, std::vector<int>& a) {
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            std::string a_str = std::to_string(a[i]);
            for (char digit : a_str) {
                if (digit >= '0' && digit <= '9') {
                    int digit_value = digit - '0';
                    if (digit_value >= 10)
                        return "NO";
                    a.insert(a.begin() + i, digit_value);
                }
            }
            a.erase(a.begin() + i + a_str.length());
            return can_sort(a.size(), a);
        }
    }
    return "YES";
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        std::cout << can_sort(n, a) << std::endl;
    }

    return 0;
}
