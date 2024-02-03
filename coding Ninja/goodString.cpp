#include <iostream>

using namespace std;

int numberOfGoodCharacters(int n, string s) {
    int count = 0;
    for (int i = 0; i < n ; i++) {
        char current = tolower(s[i]);
        char prev = tolower(s[i - 1]);
        char next = tolower(s[i + 1]);

        if ((current == 'a' || current == 'e' || current == 'i' || current == 'o' || current == 'u') ||
            (prev == 'a' || prev == 'e' || prev == 'i' || prev == 'o' || prev == 'u') ||
            (next == 'a' || next == 'e' || next == 'i' || next == 'o' || next == 'u')) {
            count++;
        }
    }
    return count;
}

int main() {
    int result = numberOfGoodCharacters(4, "aaee");
    cout << "Number of good characters: " << result << endl;

    return 0;
}
