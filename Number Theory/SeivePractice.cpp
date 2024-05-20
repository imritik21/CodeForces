#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 7;
int seive[N];
void seiveFun()
{
    fill(seive, seive + N + 1, 1);
    seive[0] = seive[1] = 0;
    for (int i = 2; i * i <= N; i++)
    {
        if (seive[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                seive[i] = 0;
            }
        }
    }
}
int countOdd(int A, int B, int N)
{
    // code here
    // basically i need to find primes btw a and b
    // vector<bool> primes;
    int cnt = 0;
    for (int i = A; i <= B; i++)
    {
        if (seive[i])
        {
            cnt++;
        }
    }
    return cnt;
}
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int A,B,N;
        cin>>A>>B>>N;
        cout<<countOdd(A,B);
    }
}