#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9 + 7
void insertSorted(std::vector<int> &A, int n)
{
    auto it = std::lower_bound(A.begin(), A.end(), n);
    A.insert(it, n);
}
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    vector<int> B;
    int maxLen = 0;
    int maxdiff = 0;
    int nextIndex;
    for (int i = 0; i + 1 < n; i++)
    {
        maxLen = max(maxLen, A[i + 1] - A[i]);
        nextIndex = (maxLen / (k + 1));
        // if((A[i + 1] - A[i])==maxLen){
        //     insertSorted(A,A[i]+nextIndex);
        //     break;
        // }
    }
    int i=1;
    while (i<=k)
    {
        for (int i = 0; i + 1 < n; i++)
        {
            if ((A[i + 1] - A[i]) == maxLen)
            {
                int r=A[i+1];
                int l=A[i];
                insertSorted(A, A[i] + nextIndex);
                B.push_back(r-(A[i] + nextIndex));
                break;
            }
        }
        i++;
    }
    ll sum = 0;
    for (int i = 0; i < B.size(); i++)
    {
        sum += B[i];
    }
    cout << sum << endl;
    // for debug
    // for (int num : A) {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;
}
