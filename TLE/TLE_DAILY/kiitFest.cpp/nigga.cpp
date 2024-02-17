#include <iostream>
#include <ctime>   // for time function
#include <cstdlib> // for srand and rand functions
#include <string>
using namespace std;

const int MAX_SIZE = 100;

class DecryptionAlgorithm {
public:
    virtual string decrypt(const string& ciphertext) = 0;
    virtual ~DecryptionAlgorithm() {}
};

class CipherDecryptor : public DecryptionAlgorithm {
public:
    string decrypt(const string& xyz) override {
        string dec = "";

        for (char c : xyz) {
            if (isalpha(c)) {
                char a = (c - 'A' - 3 + 26) % 26 + 'A';
                dec += a; // Fix: Use the decrypted character 'a'
            } else {
                dec += c;
            }
        }
        return dec;
    }
};

void Function4() {
    // Removed unused variables: vowels and consonants
}

void Function2() {
    srand(time(0));
}

void Function5(DecryptionAlgorithm* decryptor) {
    string encodedCiphertext = "\x50\x52\x55\x4C\x44\x55\x57\x42";
    string decryptedOutput = decryptor->decrypt(encodedCiphertext);
    cout << "Decrypted Output: " << decryptedOutput << endl;
}

void Function3() {
    string str = "Your Key is HERE.";
    for (char& c : str) {
        c = toupper(c);
    }
    cout << "Uppercase String: " << str << endl;
}

void Function1() {
    int sum = 0;
    for (int i = 0; i < MAX_SIZE; ++i) { // Fix: Change loop condition to i < MAX_SIZE
        sum += i;
    }
    cout << "Sum: " << sum << endl;
}

int main() {
    Function1();
    Function2();
    Function3();
    Function4(); // Fix: Corrected the function name
    CipherDecryptor sarDecryptor;
    Function5(&sarDecryptor);

    return 0;
}
