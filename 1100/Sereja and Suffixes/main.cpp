/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/368/problem/B
rating : 1100
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
  int n , m;
  cin >> n >> m;
  vector<int> vec(n);
  for(int i = 0 ; i < n ; i++) {
    cin >> vec[i];
  }

  vector<int> rep(1e5 + 1 , 0);
  vector<int> distnctNumberIn(n , 0);
  distnctNumberIn[n - 1] = 1;
  rep[vec[n - 1]] = 1;
  for(int i = n - 2 ; i > - 1 ; i--) {
    distnctNumberIn[i] = distnctNumberIn[i + 1] + (rep[vec[i]] == 0);
    rep[vec[i]] = 1;
  }

  for(int i = 0 ; i < m ; i++) {
    int x;
    cin >> x;
    cout << distnctNumberIn[x - 1] << '\n';
  }
}

int main()
{
  ios::sync_with_stdio(false);
	cin.tie(0);
  cout.tie(0);

  int t = 1;
 // cin >> t;

  while (t--)
  {
    answer();
  }

  return 0;
}