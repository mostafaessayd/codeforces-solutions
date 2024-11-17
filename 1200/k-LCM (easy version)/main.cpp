/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/1497/problem/C1
 rating : 1200
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;
const int MOD = 1e9 + 7;

void answer() {
   int n , k;
   cin >> n >> k;
   int a , b , c;
   n -= (k - 3);
   if(n & 1) {
      a = 1;
      b = c = n / 2;
   } else {
      if(n % 4 == 0) {
         a = n / 2;
         b = c = n / 4;
      } else {
         a = 2;
         b = c = (n / 2) - 1;
      }
   }

   cout << a << ' ' << b << ' ' << c;
   k -= 3;
   while(k--) {
      cout << " 1";
   }
   cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while(t--) {
        answer();
    }

    return 0;
}