/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1106/problem/D
rating : 1500
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e5;

void answer()
{
  int n , m;
  cin >> n >> m;
  vector<int> adj[n];
  for(int i = 0 ; i < m ; i++) {
     int x , y;
     cin >> x >> y;
     adj[x - 1].push_back(y - 1);
     adj[y - 1].push_back(x - 1);
  }

  set<int> pile;
  pile.insert(0);
  vector<int> vis(n , 0);
  vector<int> path(n);
  int ind = 0;
  while(pile.size()) {
    int cur_node;
    for(int u : pile) {
      cur_node = u;
      break;
    }
    vis[cur_node] = 1;
    path[ind++] = cur_node;
    pile.erase(pile.begin());

    for(int v : adj[cur_node]) {
      if(vis[v] ^ 1) {
        pile.insert(v);
      }
    }
  }

  for(int i = 0 ; i < n ; i++) {
    cout << path[i] + 1 << ' ';
  }
}

int main()
{
  int t = 1;
  // cin >> t;
  while (t--)
  {
    answer();
  }

  return 0;
}