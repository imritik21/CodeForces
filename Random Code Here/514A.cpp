#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    int n = str.size();
    for (int i = 0; i < n; i++) {
        if(i==0 && str[i]=='9')continue;
        int num = str[i] - '0'; 
        if (num >= 5) {
            num = 9 - num; 
        }
        str[i] = num + '0'; 
    }

    cout << str << endl;
    return 0;
}
