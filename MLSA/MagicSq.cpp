#include <bits/stdc++.h>
using namespace std;
int formingMagicSquare(vector<vector<int>>& s) {
    const int n = 3;
    const int magic_const = 15;  // Sum of any row, column, or diagonal in a 3x3 magic square

    // All possible 3x3 magic squares
    const std::vector<std::vector<int>> magic_squares = {
        {8, 1, 6, 3, 5, 7, 4, 9, 2},
        {6, 1, 8, 7, 5, 3, 2, 9, 4},
        {4, 9, 2, 3, 5, 7, 8, 1, 6},
        {2, 9, 4, 7, 5, 3, 6, 1, 8},
        {8, 3, 4, 1, 5, 9, 6, 7, 2},
        {4, 3, 8, 9, 5, 1, 2, 7, 6},
        {6, 7, 2, 1, 5, 9, 8, 3, 4},
        {2, 7, 6, 9, 5, 1, 4, 3, 8}
    };

    int min_cost = numeric_limits<int>::max();

    for (const auto& magic_square : magic_squares) {
        int cost = 0;
        for (int i = 0; i < n * n; ++i) {
            cost +=abs(magic_square[i] - s[i / n][i % n]);
        }
        min_cost = min(min_cost, cost);
    }

    return min_cost;
}

int main() {
    vector<vector<int>> s(3, vector<int>(3));

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> s[i][j];
        }
    }

    int result = formingMagicSquare(s);

    cout << result << endl;

    return 0;
}