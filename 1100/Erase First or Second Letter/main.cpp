/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1917/problem/B
rating : 1100
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 5e4;

void answer()
{
  int n;
  string s;
  cin >> n >> s;
  vector<int> rep(26 , 0);
  ll dist = 0;
  ll ans = 0;
  for(char ch : s) {
    if(rep[ch - 'a'] == 0) {
      dist++;
      rep[ch - 'a'] = 1;
    }
    ans += dist;
  }

  cout << ans << '\n';
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