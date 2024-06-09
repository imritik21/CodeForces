#include <iostream>
using namespace std;

int findChildWithBall(int n, int k) {
    // Start with the first child
    int curr = 0;
    // Direction is initially right (represented by +1)
    int dir = 1;

    for (int i = 0; i < k; ++i) {
        curr += dir;

        // left end pahuch
        if (curr == 0) {
            dir = 1;
        }
        //right end reverse krdo
        else if (curr == n - 1) {
            dir = -1;
        }
    }

    return curr;
}

int main() {
    int n = 5; 
    int k = 6; 

    cout<<findChildWithBall(n,k);

    return 0;
}
