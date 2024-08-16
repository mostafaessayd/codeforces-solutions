/**
created by : cidi mohamed mostepha
link : https://codeforces.com/problemset/problem/893/C
rating : 1300
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
  int n , m;
  cin >> n >> m;
  vector<int> vec(n);
  vector<vector<int>> adj(n);

  for(int i = 0 ; i < n ; i++) {
    cin >> vec[i];
  }

  for(int i = 0 ; i < m ; i++) {
    int x , y;
    cin >> x >> y;
    x--;
    y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  
  int ans = INT_MAX;
  vector<int> vis(n , 0);
  auto dfs = [&](auto self , int u)->void{
    if(vis[u]){
      return;
    }

    vis[u] = 1;
    ans = min(ans , vec[u]);

    for(int v : adj[u]){
      self(self , v);
    }
  };

  ll sum = 0;
  for(int i = 0 ; i < n ; i++) {
    if(vis[i]){
      continue;
    }
    
    ans = INT_MAX;
    dfs(dfs , i);
    sum += ans;
  }

  cout << sum << '\n';
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

