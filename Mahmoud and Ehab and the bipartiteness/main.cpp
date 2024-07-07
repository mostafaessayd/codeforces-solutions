/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/862/problem/B
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
  vector<int> a , b;
  for(int i = 0 ; i < n - 1 ; i++) {
    int x , y;
    cin >> x >> y;
    x--;
    y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  auto dfs = [&](auto self , int v , int p , vector<int>&a , vector<int>&b)->void {
    a.push_back(v);
    for(int u : adj[v]) {
      if(u != p) {
        self(self , u , v , b , a);
      }
    }
  };

  dfs(dfs , 0 , -1 , a , b);

  ll l1 = a.size();
  ll l2 = b.size();

  cout << l1 * l2 - 1ll * (n - 1);
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