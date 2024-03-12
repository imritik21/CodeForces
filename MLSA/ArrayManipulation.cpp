#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<long long> arr(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int a, b;
        long long k;
        std::cin >> a >> b >> k;

        arr[a] += k;
        if (b + 1 <= n) {
            arr[b + 1] -= k;
        }
    }

    long long max_value = 0, current_value = 0;

    for (int i = 1; i <= n; ++i) {
        current_value += arr[i];
        max_value = std::max(max_value, current_value);
    }

    std::cout << max_value << std::endl;

    return 0;
}