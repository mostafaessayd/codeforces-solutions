/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/129/problem/B
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 5e4;

void answer()
{
  int n , m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for(int i = 0 ; i < m ; i++) {
    int x , y;
    cin >> x >> y;
    x--;
    y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  int ans = 0;
  vector<int> vis(n , 0);
  while(1) {
    bool new_state = false;
    vector<int> current_round(n , 0);
    for(int i = 0 ; i < n ; i++) {
      if(current_round[i] == 1 || vis[i] == 1) {
        continue;
      }

      if(adj[i].size() == 1) {
        new_state = true;
        int per = adj[i][0];
        current_round[per] = 1;
        vis[i] = 1;
        adj[per].erase(remove(adj[per].begin() , adj[per].end() , i) , adj[per].end());
      }
    }
    
    if(new_state) {
      ans++;
    } else {
      break;
    }
  } 
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