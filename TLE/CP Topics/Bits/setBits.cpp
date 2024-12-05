#include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int number = 13; // Binary: 1101
//     int bitPosition = 3; // We want to check the 0th bit
    
//     // Create a mask with only the bit at `bitPosition` set
//     int mask = 1 << bitPosition;
    
//     // Perform the bitwise AND to check if the bit at `bitPosition` is set
//     if (number & mask) {
//         cout << "The " << bitPosition << "th bit is set." << endl;
//     } else {
//         cout << "The " << bitPosition << "th bit is not set." << endl;
//     }

//     return 0;
// }
// #include <iostream>
using namespace std;

int main() {
    int number = 13; // Binary: 1101
    int bitPosition = 4; // We want to unset the 3rd bit
    int ans = log2(number);
    cout<<ans+1<<endl;
    // Create a mask with all bits set to 1 except the bit at `bitPosition`
    int mask = ~(1 << bitPosition);
    
    // Perform the bitwise AND with the inverted mask to unset the bit
    number = number & mask;

    cout << "Number after unsetting the " << bitPosition << "th bit: " << number << endl;
    
    return 0;
}
