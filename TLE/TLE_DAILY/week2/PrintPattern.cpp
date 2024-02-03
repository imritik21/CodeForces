#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;

    int n = 1;

    for (int i = 1; i <= num; i++) {
        if (i % 2 == 1) {
            // Print in descending order for odd rows
            int start = n + i - 1;
            for (int j = 1; j <= i; j++) {
                cout << start-- << " ";
            }
            n += i;
        } else {
            
            // Print in ascending order for even rows
            for (int j = 1; j <= i; j++) {
                cout << n++ << " ";
            }
        }

        cout << endl;
    }

    return 0;
}
