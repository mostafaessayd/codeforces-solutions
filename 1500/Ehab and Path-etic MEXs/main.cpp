/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1325/problem/C
rating : 1500
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  vector<pair<int , int>> edges(n - 1);
  for(int i = 0 ; i < n - 1 ; i++) {
    cin >> edges[i].first >> edges[i].second;
    edges[i].first--;
    edges[i].second--;
    adj[edges[i].first].push_back(edges[i].second);
    adj[edges[i].second].push_back(edges[i].first);
  }

  vector<int> vis(n , 0);
  for(int i = 0 ; i < n ; i++) {
    if(adj[i].size() >= 3) {
      vis[i] = 1;
      for(int j = 0 ; j < 3 ; j++) {
        vis[adj[i][j]] = 1;
      }
      break;
    }
  }
  
   int val1 = 0;
   int val2 = n - 2;
  for(int i = 0 ; i < n - 1 ; i++) {
    if(vis[edges[i].first] && vis[edges[i].second]) {
      cout << val1++ << '\n';
    } else {
      cout << val2--<< '\n';
    }
  }
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