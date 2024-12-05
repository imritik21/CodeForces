#include<bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    ofstream outFile("example.txt");
    outFile << "Name: Ritik Shankar\n"
               "Roll: 2228132\n"
               "Add: kp-12 Patia\n";
    outFile.close();

    // now read from files
    ifstream inFile("example.txt");
    string line, name, address;

    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            
            if (line.find("Name:") != std::string::npos) {
                name = line.substr(line.find(":") + 2); 
            } else if (line.find("Add:") != std::string::npos) {
                address = line.substr(line.find(":") + 2);
            }
        }
        inFile.close();
    } 

    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;

    return 0;
}
