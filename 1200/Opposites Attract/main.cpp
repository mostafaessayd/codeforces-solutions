/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/131/problem/B
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;
const int MOD = 1e9 + 7;

void answer() {
   int n;
   cin >> n;
   vector<int> pos(11 , 0) , neg(11 , 0);
   vector<int> vec;
   ll zero = 0;
   for(int i = 0 ; i < n ; i++) {
      int x;
      cin >> x;
      vec.push_back(x);
      zero += (x == 0);
      if(x < 0) {
         neg[-1 * x]++;
      } else if (x > 0) {
         pos[x]++;
      }
      
   }

   ll ans = 0;
   for(int i : vec) {
      if(i > 0) {
         ans += 1ll * neg[i];
      } else if(i < 0) {
         ans += 1ll * pos[-1 * i];
      }
   }
   
   zero = (zero * (zero - 1)) / 2;
   ans /= 2;
   ans += zero;
   cout << ans;
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