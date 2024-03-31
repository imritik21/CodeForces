#include <iostream>
#include <cmath>

using namespace std;

bool isProductOfBinaryDecimals(int n) {
    if (n <= 0) {
        return false; // Non-positive numbers cannot be products of binary decimals
    }

    // Handle the special case of n being 1
    if (n == 1) {
        return true;
    }

    // Check if n is even. If not, it can't be a product of binary decimals.
    if (n % 2 != 0) {
        return false;
    }

    // Efficiently divide n by 2 repeatedly until it becomes 1 or odd.
    while (n % 2 == 0) {
        n /= 2;
    }

    // If n is not 1 after division, it's not a product of binary decimals.
    return n == 1;
}

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    if (isProductOfBinaryDecimals(n)) {
        cout << n << " can be represented as a product of binary decimals." << endl;
    } else {
        cout << n << " cannot be represented as a product of binary decimals." << endl;
    }

    return 0;
}
