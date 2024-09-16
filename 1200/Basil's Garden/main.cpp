/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1987/problem/C
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
  int n;
  cin >> n;

  vector<int> vec(n);

  for(int i = 0 ; i < n ; i++) {
    cin >> vec[i];
  }

  int ans = 0;
  for(int i = 0 ; i < n ; i++) {
    ans = max(ans , vec[i] + i);
  }

  cout << ans << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
	cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;

  while (t--)
  {
    answer();
  }

  return 0;
}