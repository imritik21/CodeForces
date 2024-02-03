/*Given N numbers. Count how many of these values are even, odd, positive and negative.

Input
First line contains one number N (1 ≤ N ≤ 103) number of values.

Second line contains N numbers (-105 ≤ Xi ≤ 105).

Output
Print four lines with the following format:

First Line: "Even: X", where X is the number of even numbers in the given input.

Second Line: "Odd: X", where X is the number of odd numbers in the given input.

Third Line: "Positive: X", where X is the number of positive numbers in the given input.

Fourth Line: "Negative: X", where X is the number of negative numbers in the given input.*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int even = 0;
    int odd = 0;
    int pos = 0;
    int neg = 0;
    int x[N];
    for (int i = 0; i < N; i++)
    {
        cin>>x[i];
        if(x[i]%2==0)
        even++;
        else
        odd++;
        if(x[i]>0)
        pos++;
        else if(x[i]<0)
        neg++;
    }

    cout << "Even:"
         << " " << even << endl;
    cout << "Odd:"
         << " " << odd << endl;
    cout << "Positive:"
         << " " << pos << endl;
    cout << "Negative:"
         << " " << neg << endl;
}