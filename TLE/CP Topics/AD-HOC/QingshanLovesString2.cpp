
// /* Programmed by : https://www.linkedin.com/in/ritik-shankar-537741264/ */

// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// #define fast_cin()                    \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL);                    \
//     cout.tie(NULL)
// #define all(x) (x).begin(), (x).end()
// #define sz(x) ((ll)(x).size())

// int main()
// {
//     fast_cin();
//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         string s;
//         cin >> s;
//         // int n = s.size();
//         int cz = 0, co = 0;
//         for (int i = 0; i < s.size(); i++)
//         {
//             cz+=s[i]=='0';
//             co+=s[i]=='1';
//         }
//         if (cz != co)
//         {
//             cout << -1 << endl;
//             continue;
//         }
//         vector<int> ans;
//         deque<char> chars;
//         for (int i = 0; i < s.size(); i++)
//         {
//             chars.push_back(s[i]);
//         }
//         int d = 0;
//         while (!chars.empty())
//         { // O(n)
//             if (chars.front() == chars.back())
//             {
//                 if (chars.front() == '0')
//                 {
//                     chars.push_back('0');
//                     chars.push_back('1');
//                     ans.push_back(n - d);
//                 }
//                 else
//                 {

//                     chars.push_back('1');
//                     chars.push_back('0');
//                     ans.push_back(0 + d);
//                 }
//                 n += 2;
//             }
            
//             while (!chars.empty() && chars.front() != chars.back())
//             {
//                 chars.pop_back();
//                 chars.pop_front();
//                 ++d;
//             }
//         }
//         cout << ans.size() << endl;
//         for(int i=0;i<ans.size();i++){
//             cout<<ans[i];
//             if(i+1==ans.size())cout<<endl;
//             else cout<<" ";
//         }
//     }
//     return 0;
// }
#include <bits/stdc++.h>

bool ok(std::string s) {
  for (size_t i = 1; i < s.length(); ++i)
    if (s[i] == s[i - 1])
      return false;
  return true;
}


std::string s;
void solve() {
  int n; std::cin >> n;
  std::cin >> s;
  int cnt0 = 0, cnt1 = 0;
  for (int i = 0; i < s.length(); ++i) {
    cnt0 += s[i] == '0';
    cnt1 += s[i] == '1';
  }
  if (cnt0 != cnt1) {
    std::cout << -1 << std::endl;
    return;
  }
  std::vector<int> z;
  std::deque<char> q;
  for (int i = 0; i < s.length(); ++i)
    q.push_back(s[i]);
  
  int d = 0;
  while (!q.empty()) {
    if (q.front() == q.back()) {
      if (q.front() == '0') {
        q.push_back('0');
        q.push_back('1');
        z.push_back(n - d);
      } else {
        q.push_front('1');
        q.push_front('0');
        z.push_back(0 + d);
      }
      n += 2;
    }
    while (!q.empty() && q.front() != q.back()) {
      q.pop_back();
      q.pop_front();
      ++d;
    }
  }

  std::cout << z.size() << std::endl;
//   std::cout<<std::endl;
    if(z.size()==0)std::cout<<std::endl;
  for (int i = 0; i < z.size(); ++i) {
    std::cout << z[i];
    if (i + 1 == z.size()) std::cout << std::endl;
    else std::cout << " ";
  }
}

int main() {
  int t;
  std::cin >> t;
  while (t--) solve();
  return 0;
}