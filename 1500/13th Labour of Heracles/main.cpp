/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1466/problem/D
rating : 1500
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;

void answer() {
   int n;
   cin >> n;
   vector<int> wights(n);
   for(int& w : wights) cin >> w;

   vector<vector<int>> adj(n);
   for(int i = 0 ; i < n - 1 ; i++) {
      int u , v;
      cin >> u >> v;
      u--;
      v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
   
   vector<ll> ans;
   auto dfs = [&](auto self , int u , int p = -1) -> void {
      for(int i = 0 ; i < adj[u].size() ; i++) {
         if(i > 0) {
            ans.push_back(wights[u]);
         }
         if(adj[u][i] == p) continue;
         self(self , adj[u][i] , u);
      }
   };

   for(int u = 0 ; u < n ; u++) {
      if(adj[u].size() > 1) {
         dfs(dfs , u);
         break;
      }
   }

   sort(ans.rbegin() , ans.rend());

   ll sum = accumulate(wights.begin() , wights.end() , 0LL);
   cout << sum << ' ';
   for(int i = 0 ; i < n - 2 ; i++) {
      sum += ans[i];
      cout << sum << ' ';
   }
   cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while(t--) {
        answer();
    }

    return 0;
}