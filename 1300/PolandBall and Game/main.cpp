/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/755/problem/C
rating : 1300
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
  int n;
  cin >> n;

  vector<vector<int>> adj(n);
  for(int i = 0 ; i < n ; i++) {
    int x;
    cin >> x;
    x--;
    adj[i].push_back(x);
    adj[x].push_back(i);
  }

  vector<int> vis(n , 0);
  auto dfs = [&](auto self , int v)->void {
   if(vis[v]) {
    return;
   }

   vis[v] = 1;
   for(int u : adj[v]) {
    if(vis[u] == 0) {
      self(self , u);
    }
   }
  };

  int ans = 0;
  for(int i = 0 ; i < n ; i++) {
    if(vis[i]) {
      continue;
    }
    ans++;
    dfs(dfs , i);
  }

  cout << ans << '\n';
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