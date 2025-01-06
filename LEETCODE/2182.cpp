#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
string repeatLimitedString(string s, int limit)
{
    int n = s.size();
    vector<int> freq(26, 0);

    // Count the frequency of each character
    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
    }

    string ans = "";
    int i = 25; // Start from the largest character ('z')

    while (i >= 0) {
        if (freq[i] == 0) {
            i--;
            continue;
        }

        // Add up to 'limit' occurrences of the current character
        int use = min(limit, freq[i]);
        freq[i] -= use;

        for (int j = 0; j < use; j++) {
            ans += (char)(i + 'a');
        }

        // If more of this character is left, find the next valid character
        if (freq[i] > 0) {
            int j = i - 1;
            while (j >= 0 && freq[j] == 0) {
                j--;
            }

            if (j >= 0) {
                ans += (char)(j + 'a'); // Add one occurrence of the next valid character
                freq[j]--;
            } else {
                break; // No valid characters left to interleave
            }
        } else {
            i--; // Move to the next smaller character
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    int limit;
    cin>>s>>limit;
    cout<<repeatLimitedString(s,limit)<<endl;
    return 0;
}
