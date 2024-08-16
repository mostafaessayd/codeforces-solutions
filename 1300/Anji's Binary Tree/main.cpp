/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/1900/problem/C
 rating : 1300
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
  int n;
  string s;
  cin >> n >> s;

  vector<pair<int , int>> adj(n);
  for(int i = 0 ; i < n ; i++) {
    int x , y;
    cin >> x >> y;
    x--;
    y--;
    adj[i].first = x;
    adj[i].second = y;
  }

  auto dfs = [&](auto self , int v , string& s)->ll {
    if(v == -1) {
      return INT_MAX;
    }

    if(adj[v].first == -1 && adj[v].second == -1) {
      return 0;
    }

    ll L = self(self , adj[v].first , s) + (s[v] != 'L');
    ll R = self(self , adj[v].second , s) + (s[v] != 'R');

    return min(1ll * L , 1ll * R);
  };

  cout << dfs(dfs , 0 , s) << '\n';
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