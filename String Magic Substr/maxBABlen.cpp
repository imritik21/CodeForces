#include <bits/stdc++.h>
using namespace std;

int maxBabLength(const string& str) {
    int maxLength = 0;  
    int currentLength = 0;  // 

    for (size_t i = 0; i < str.length() - 2;) {
        if (str.substr(i, 3) == "bab") {
            cout<<i<<" ";
            currentLength += 2;
            i += 2;  
            if(i+1<str.size() && str[i+1]=='a' && i+1==str.size()-1)currentLength+=1;
            if(i==str.size()-1)currentLength+=1;
        } else {
            maxLength = max(maxLength, currentLength);
            currentLength = 0;
            i++;
        }
    }

    maxLength = max(maxLength, currentLength);
    return maxLength;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    int result = maxBabLength(str);
    cout << "The maximum length of consecutive 'bab' is: " << result << endl;

    return 0;
}
