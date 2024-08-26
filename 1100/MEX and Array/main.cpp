/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1637/problem/B
rating : 1100
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 5e4;

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
    vector<int> stock;
    int zero = 0;
    for(int j = i ; j < n ; j++) {
      stock.push_back(vec[j]);
      zero += (vec[j] == 0);
      ans += stock.size() + zero;
    }
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