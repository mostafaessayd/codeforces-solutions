/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1208/problem/B
rating : 1500
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
  int n;
  cin >> n;
  vector<int> vec(n);
  for (int &val : vec)
  {
    cin >> val;
  }

  int ans = INT_MAX;
  set<int> dp;
  for (int i = 0; i < n; i++)
  {
    if (dp.count(vec[i]))
    {
      break;
    }
    dp.insert(vec[i]);
    set<int> temp = dp;
    int r = n - 1;
    while (r >= i && !temp.count(vec[r]))
    {
      temp.insert(vec[r]);
      r--;
    }
    ans = min(ans, r - i);
  }

  set<int> temp;
  int r = n - 1;
  while (r >= 0 && !temp.count(vec[r]))
  {
    temp.insert(vec[r]);
    r--;
  }

  ans = min(ans, r + 1);

  cout << ans;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int t = 1;
  // cin >> t;
  while (t--)
  {
    answer();
  }

  return 0;
}