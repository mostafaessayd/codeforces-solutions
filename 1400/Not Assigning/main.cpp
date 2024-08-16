/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1627/problem/C
rating : 1400
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
  int n;
  cin >> n;
  
  vector<vector<pair<int , int>>> adj(n);
  vector<int> degree(n);
  vector<int> values(n - 1);

  for(int i = 0 ; i < n - 1 ; i++) {
    int x , y;
    cin >> x >> y;
    x--;
    y--;
    adj[x].push_back({y , i});
    adj[y].push_back({x , i});
    degree[x]++;
    degree[y]++;
  }

  if(n == 2) {
    cout << "2\n";
    return;
  }

  if(*max_element(degree.begin() , degree.end()) > 2) {
    cout << "-1\n";
    return;
  }else {
    auto dfs = [&](auto self , int u , int p , int last)->void {
      for(pair<int , int> ind : adj[u]) {
        if(ind.first != p) {
          values[ind.second] = (last == 2 ? 5 : 2);
          last = (last == 2 ? 5 : 2);
          self(self , ind.first , u , last);
        }
      }
    };

    dfs(dfs , 0 , -1 , 2);
    for(int i = 0 ; i < n - 1 ; i++) {
      cout << values[i] << ' ';
    }

    cout << '\n';
  }
  
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