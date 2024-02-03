/*Monocarp is a great solver of adhoc problems. Recently, he participated in an Educational Codeforces Round, and gained rating!

Monocarp knew that, before the round, his rating was a. After the round, it increased to b
(b>a). He wrote both values one after another to not forget them.

However, he wrote them so close to each other, that he can't tell now where the first value ends and the second value starts.

Please, help him find some values a
 and b such that:
neither of them has a leading zero;
both of them are strictly greater than 0;
b>a;
they produce the given value ab when written one after another.If there are multiple answers, you can print any of them.

Input
The first line contains a single integer t(1≤t≤104) — the number of testcases.

The only line of each testcase consists of a single string ab of length from 2to 8that:

consists only of digits;
doesn't start with a zero.*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string ab;
        cin >> ab;

        bool found = false;

        for (int i = 1; i < ab.length(); ++i) {
            string astr = ab.substr(0, i);
            string bstr = ab.substr(i);

            if (astr[0] != '0' && bstr[0] != '0' && stoll(bstr) > stoll(astr)) {
                cout << astr << " " << bstr << endl;
                found = true;
                break; 
            }
        }

        if (!found) {
            cout << "-1" << endl;
        }
    }

    return 0;
}



