/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/763/problem/A
rating : 1600
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;

void answer() {
   int n;
   cin >> n;
   vector<vector<int>> adj(n);
   for(int i = 0 ; i < n - 1 ; i++) {
      int u , v;
      cin >> u >> v;
      u--;
      v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }

   vector<int> colors(n);
   int last = -1;
   bool same = true;
   for(int& color : colors) {
      cin >> color;
      if(last != -1) {
         if(color != last) {
            same = false;
         }
      }
      last = color;
   }
   
   if(same) {
      cout << "YES\n1";
      return;
   }

   set<int> roots;
   auto dfs1 = [&](auto self , int u , int p = -1) -> void {
      bool same = true;
      for(int v : adj[u]) {
         if(colors[v] != colors[u]) {
            roots.insert(v);
            roots.insert(u);
            same = false;
         }
      }

      if(!same) {
         return;
      }

      for(int v : adj[u]) {
         if(v == p) continue;
         self(self , v , u);
      }
   };
   
   auto dfs2 = [&](auto self , int u , int p) -> bool {
      bool ans = true;
      for(int v : adj[u]) {
         if(v == p) continue;
         ans &= (colors[v] == colors[u]);
         ans &= self(self , v , u);
      }
      return ans;
   };

   dfs1(dfs1 , 0 , -1);
   
   for(int root : roots) {
      bool ans = true;
      for(int p : adj[root]) {
         ans &= dfs2(dfs2 , p , root);
      }
      if(ans) {
         cout << "YES\n" << root + 1;
         return;
      }
   }

   cout << "NO\n";
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
