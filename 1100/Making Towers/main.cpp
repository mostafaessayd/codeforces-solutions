/**
 * created by : cidi mohamed mostepha
 * link :https://codeforces.com/contest/1706/problem/B
 * rating : 1100
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
  map<int , vector<int>> indices;
  for(int i = 0 ; i < n ; i++) {
    cin >> vec[i];
    indices[vec[i]].push_back(i);
  }

  vector<int> ans(n + 1 , 0);
  for(auto ind : indices) {
    ans[ind.first] = 1;
    for(int i = 0 ; i < ind.second.size() - 1 ; i++) {
      ans[ind.first] += (ind.second[i + 1] - ind.second[i]) % 2;
    }
  }

  for(int i = 0 ; i < n ; i++) {
    cout << ans[i + 1] << " \n"[i == n - 1];
  }
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