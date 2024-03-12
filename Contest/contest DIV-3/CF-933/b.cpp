#include<bits/stdc++.h>
using namespace std;
int main() {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);

     int t;
     cin >> t;
     while(t--) {
         long long int n;
         cin >> n;
         vector<long long int> a(n);
         for(int i = 0; i < n; i++) {
             cin >> a[i];
         }

         bool possible = true;
         while(true) {
             bool ops = false;
             for(int i = 1; i < n - 1; i++) {
                 if(a[i - 1] > 0 && a[i] > 1 && a[i + 1] > 0) {
                     a[i - 1]--;
                     a[i] -= 2;
                     a[i + 1]--;
                     ops = true;
                 }
             }
      
         }

         for(long long int i = 0; i < n; i++) {
             if(a[i] != 0) {
                 possible = false;
                 break;
             }
         }

         if(possible) {
             cout << "yEs\n";
         } else {
             cout << "nO\n";
         }
     }

     return 0;
 }