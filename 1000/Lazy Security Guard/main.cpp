/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/859/problem/B
 rating : 1000
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 5e4;

void answer()
{
  int n;
  cin >> n;
  int ans = INT_MAX;
  for(int i = 1 ; i <= n ; i++) {
    ans = min(ans , 2 * (i + n / i) + 2 * (n % i ? 1 : 0));
  }

  cout << ans;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int t = 1;
  //cin >> t;
  while (t--)
  {
    answer();
  }

  return 0;
}