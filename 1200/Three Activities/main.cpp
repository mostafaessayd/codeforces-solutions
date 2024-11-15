/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1914/problem/D
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
  vector<pair<int , int>> a(n) , b(n) , c(n);
  for(int i = 0 ; i < n ; i++) {
   cin >> a[i].first;
   a[i].second = i;
  }
  for(int i = 0 ; i < n ; i++) {
   cin >> b[i].first;
   b[i].second = i;
  }
  for(int i = 0 ; i < n ; i++) {
   cin >> c[i].first;
   c[i].second = i;
  }

  sort(a.rbegin() , a.rend());
  sort(b.rbegin() , b.rend());
  sort(c.rbegin() , c.rend());

  ll ans = 0;
  for(int i = 0 ; i < 3 ; i++) {
   for(int j = 0 ; j < 3 ; j++) {
      for(int k = 0 ; k < 3 ; k++) {
         if(a[i].second != b[j].second && a[i].second != c[k].second && b[j].second != c[k].second) {
            ans = max(ans , 1ll * (a[i].first + b[j].first + c[k].first));
         }
      }
   }
  }

  cout << ans << '\n';
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
