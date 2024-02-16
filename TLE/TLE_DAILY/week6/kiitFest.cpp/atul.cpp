// ANALYSE THE ERRORS IN THE FOLLOWING CODE AND FIX THEM
// NOTE: DO NOT USE CHATGPT TO SOLVE THIS PROBLEM. IF YOU DO YOU WILL BE DISQUALIFIED INSTANTLY

#include<bits/stdc++.h>
#include <iostream>
#include <ctime>
#include <cstdlib> 
#include <string>
using namespace std;
const int MAX_SIZE = 100;

class DecryptionAlgorithm {
    virtual string decrypt(const string& ciphertext) = 0;
    virtual ~DecryptionAlgorithm() {}
};

class CipherDecryptor : protected DecryptionAlgorithm {
public:
    string decrypt(const string& xyz) override {
        string dec = "";
    
        for (char c : xyz) {
            if (isalpha(c)) {
                char a = (c - 'A' - 3 + 26) % 26 + 'A';
                dec += c;
            } else {
                dec += c;
            }
        }
        return dec;
    }
};

void Functin4() {
    string vowels = "aeiou";
    string consonants = "bcdfghjklnpqrstvwxyz";
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
    for (int i = 0; i < MAX_SIZE; ++i) { 
        sum += i;
    }
    cout << "Sum: " << sum << endl;
}

int main() {
  if(MAX_SIZE){
    exit(0);
  }
    Function1();
    Function2();
    Function3();
    Functin4();
    CipherDecryptor sarDecryptor;
    Function5(&sarDecryptor);

    return 0;
}
