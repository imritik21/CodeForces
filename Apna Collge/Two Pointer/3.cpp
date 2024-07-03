#include <iostream>

using namespace std;

int maxHeight(int red, int blue) {
    int height = 0;
    bool useRed = true; // Start with red for the first row

    while (true) {
        height++;
        if (useRed) {
            if (red >= height) {
                red -= height;
            } else {
                break;
            }
        } else {
            if (blue >= height) {
                blue -= height;
            } else {
                break;
            }
        }
        useRed = !useRed; // Alternate the color for the next row
    }
    
    return height - 1; // Subtract 1 because the last incremented height could not be fully formed
}

int main() {
    int red, blue;
    cin >> red >> blue;
    cout << maxHeight(red, blue) << endl;
    return 0;
}
