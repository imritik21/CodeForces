#include <iostream>
using namespace std;

int main() {
    int a = 11, b = 44;
    int step = 0;  // Ensure step is initialized

    for (int i = 1; i <= 3; i++) {
        if (a == b) {
            break;
        }
        // cout << (a << i) << endl;
        a= (a<<1);
        cout<<a<<endl;
        step++;
    }
    cout << step;
    return 0;
}
