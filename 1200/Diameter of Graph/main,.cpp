/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1581/problem/B
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 101;

void answer()
{
  ll n , m , k;
  cin >> n >> m >> k;
  if(m > n * (n - 1) / 2 || m + 1 < n) {
    cout << "NO\n";
    return;
  }
  
  if(n == 1) {
    if(k > 1) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
    return;
  }

  ll d;
  if(m == n * (n - 1) / 2) {
    d = 1;
  } else {
    d = 2;
  }

  cout << (d < k - 1 ? "YES\n" : "NO\n") << '\n';
}

int main()
{
  ios_base::sync_with_stdio(0);
  int t = 1;
  cin >> t;
  while (t--)
  {
    answer();
  }

  return 0;
}