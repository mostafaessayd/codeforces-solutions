/**
 * created by : cidi mohamed mostepha
 * link :https://codeforces.com/contest/1618/problem/C
 * rating : 1100
 */

#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void answer() {
  int n;
  cin >> n;
  vector<ll> vec(n);
  for(ll& val : vec) {
    cin >> val;
  }

  ll x = vec[0];
  ll y = vec[1];
  for(int i = 2 ; i < n ; i++) {
    if(i & 1) {
      y = __gcd(y , vec[i]);
    } else {
      x = __gcd(x , vec[i]);
    }
  }

  bool even = true;
  bool odd = true;
  for(int i = 0 ; i < n ; i++) {
    if(i & 1) {
      if(vec[i] % x == 0) {
        odd = false;
      }
    } else {
      if(vec[i] % y == 0) {
        even = false;
      }
    }
  }
  if(odd) {
    cout << x << '\n';
  } else {
    if(even) {
      cout << y << '\n';
    } else {
      cout << "0\n";
    }
  }
}

int main() {
  int t = 1;
  cin >> t;
  while(t--) {
    answer();
  }
  return 0;
}
