#include<bits/stdc++.h>
using namespace std;

int main() {
    ifstream inFile("addition.c");

    ofstream outFile("multiplication.c");
    

    string line;
    while (getline(inFile, line)) {
        size_t pos;
        while ((pos = line.find("+")) != std::string::npos) {
            line.replace(pos, 1, "*");  // Replace 
        }
        outFile << line << endl;
    }

    inFile.close();
    outFile.close();

    cout << "The file has been modified and saved as 'multiplication.c'." << endl;
    return 0;
}
