/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1037/problem/D
rating : 1700
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  for(int i = 0 ; i < n - 1 ; i++) {
    int x , y;
    cin >> x >> y;
    x--;
    y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  vector<int> vec(n);
  vector<int> dest(n , 0);
  for(int i = 0 ; i < n ; i++) {
    cin >> vec[i];
    vec[i]--;
    dest[vec[i]] = i;
  }

  vector<int> validBfs;
  vector<int> vis(n , 0);

  auto bfs = [&](auto self , vector<int>&vec)->void {
    if(vec.size() == 0) {
      return;
    }

    int start = vec.front();
    validBfs.push_back(start);
    vis[start] = 1;
    vec.erase(vec.begin());
    for(int i = 0 ; i < adj[start].size() ; i++) {
      if(vis[adj[start][i]] == 0) {
        vec.push_back(adj[start][i]);
      }
    }

    self(self , vec);
  };

  vector<int> pile;
  pile.push_back(0);

  for(int i = 0 ; i < n ; i++) {
    sort(adj[i].begin() , adj[i].end() , [&](int x , int y)->bool{
      return dest[x] < dest[y];
    });
  }

  bfs(bfs , pile);

  for(int i = 0 ; i < validBfs.size() ; i++) {
    if(vec[i] != validBfs[i]) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
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