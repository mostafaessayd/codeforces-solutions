/**
 * created by : cidi mohamed mostepha
 * link : https://codeforces.com/contest/1132/problem/B
 * rating : 900
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 5e4;

void answer()
{
  int n;
  cin >> n;
  vector<ll> vec(n);
  for(ll& val : vec) {
    cin >> val;
  }
  sort(vec.rbegin() , vec.rend());
  vector<ll> suffix(n);
  ll sum = 0;
  for(int i = n - 1 ; i > -1 ; i--) {
    sum += vec[i];
    suffix[i] = sum;
  }
  vector<ll> prefix(n);
  sum = 0;
  for(int i = 0 ; i < n ; i++) {
    sum += vec[i];
    prefix[i] = sum;
  }

  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    x--;
    cout << prefix[x - 1] + (x == n - 1 ? 0 : suffix[x + 1]) << '\n';
  }
  
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