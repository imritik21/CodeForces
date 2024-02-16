#include <iostream>

using namespace std;

int main() {
    int operations, glass_capacity, mug_capacity;
    int glass_water = 0, mug_water = 0;

    // take input
    cin >> K;
    cin >> glass_capacity;
    cin >> mug_capacity;

    // perform operations
    for (int i = 1; i <= K; i++) {
        if (i == 1) {
            mug_water = mug_capacity;
        }
        if (i == 2) {
            int transfer = min(mug_water, glass_capacity);
            glass_water += transfer;
            mug_water -= transfer;
        }
        if (i == 3) {
            glass_water = 0;
        }
        if (i == 4) {
            int transfer = min(mug_water, glass_capacity - glass_water);
            glass_water += transfer;
            mug_water -= transfer;
        }
        if (i == 5) {
            mug_water = mug_capacity;
        }
    }

    cout<< glass_water <<" "<<mug_water;

    return 0;
}
