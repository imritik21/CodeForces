#include <bits/stdc++.h>
using namespace std;

void replaceSubstring(std::string& source, size_t start, size_t length, const std::string& replacement) {
    
    string before = source.substr(0, start);

    string after = source.substr(start + length);
    source = before + replacement + after;
}
int main() {
    ifstream sourceFile("src.c");
    ifstream modifierFile("modifier.c");
    ofstream outputFile("modified.c");

    string sourceCode;
    string line;
    while (getline(sourceFile, line)) {
        sourceCode += line + "\n";
    }

    string modifierCode;
    while (getline(modifierFile, line)) {
        modifierCode += line + "\n";
    }

    sourceFile.close();
    modifierFile.close();
    size_t funcStart = sourceCode.find("int main()");
    // cout<<funcStart<<endl;
    // cout<<std::string::npos<<endl;
    if (funcStart != string::npos) {
        size_t funcEnd = sourceCode.find("}", funcStart) + 1;

        if (funcEnd != string::npos) {
            replaceSubstring(sourceCode, funcStart, funcEnd - funcStart, modifierCode);
        }
    }
    
    cout<<sourceCode<<endl;
    cout<<modifierCode<<endl;
    outputFile << sourceCode;

    outputFile.close();

    cout << "Modified content saved as 'modified.c'." << endl;
    return 0;
}
