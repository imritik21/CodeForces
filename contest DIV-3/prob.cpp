// #include <iostream>
// #include <string>
// #include <unordered_set>
// using namespace std;

// int main() {
//     int t;
//     cin >> t;

//     while (t--) {
//         int n;
//         cin >> n;
//         string log;
//         cin >> log;

//         unordered_set<char> solved;
//         int count = 0;

//         for (int i = 0; i < n; i++) {
//             if (solved.find(log[i]) == solved.end()) {
//                 solved.insert(log[i]);
//                 count++;
//             }
//         }

//         cout << count << endl;
//     }

//     return 0;
// }
#include <iostream>
#include <string>
#include <unordered_map>
    using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        string log;
        cin >> log;

        unordered_map<char, int> timeTaken;
        int totalTime = 0;

        for (int i = 0; i < 26; i++)
        {
            char problem = 'A' + i;
            int time;
            cin >> time;
            timeTaken[problem] = time;
        }

        unordered_map<char, int> lastSolved;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            char problem = log[i];
            if (i - lastSolved[problem] >= timeTaken[problem])
            {
                count++;
            }
            lastSolved[problem] = i;
        }

        cout << count << endl;
    }

    return 0;
}