/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/930/problem/A
rating : 1500
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;
const int MOD = 1e9 + 7;

void answer() {
   int n;
   cin >> n;
   vector<vector<int>> adj(n);
   for(int i = 1 ; i < n ; i++) {
      int u;
      cin >> u;
      u--;
      adj[u].push_back(i);
      adj[i].push_back(u);
   }
   
   vector<int> Level(n + 1 , 0);
   auto dfs = [&](auto self , int u = 0 , int p = -1 , int d = 0) -> void {
      Level[d] ^= 1;
      for(int v : adj[u]) {
         if(v == p) continue;
         self(self , v , u , d + 1);
      }
   };
   
   dfs(dfs);
   int ans = accumulate(Level.begin() , Level.end() , 0);
   cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    while(t--) {
        answer();
    }

    return 0;
}