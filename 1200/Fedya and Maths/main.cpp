/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/456/problem/B
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;
const int MOD = 1e9 + 7;

void answer() {
   string n;
   cin >> n;
   if(n.size() == 1) {
      if(n == "4" || n == "8" || n == "0") {
         cout << "4";
      } else {
         cout << "0";
      } 
   } else {
      int last;
      for(int i = 0 ; i < n.size() - 1 ; i++) {
         last = (n[i] - '0') * 10 + (n[i + 1] - '0');
      }

      cout << (last % 4 == 0 ? "4" : "0");
   }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
   // cin >> t;
    while(t--) {
        answer();
    }

    return 0;
}