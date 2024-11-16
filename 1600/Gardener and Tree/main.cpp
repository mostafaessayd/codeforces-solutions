/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1593/problem/E
rating : 1600
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;
const int MOD = 1e9 + 7;

void answer() {
   int n , k;
   cin >> n >> k;
   vector<vector<int>> adj(n);
   vector<int> degree(n , 0);
   for(int i = 1 ; i < n ; i++) {
      int u , v;
      cin >> u >> v;
      u--;
      v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
      degree[u]++;
      degree[v]++;
   }
   
   vector<int> valueOfDelete(n , 0);
   deque<int> q;
   for(int i = 0 ; i < n ; i++) {
      if(degree[i] == 1) {
         q.push_back(i);
         valueOfDelete[i] = 1;
      }
   }

   while(!q.empty()) {
      int u = q.front();
      q.pop_front();
      for(int v : adj[u]) {
         if(degree[v] > 1) {
            degree[v]--;
            if(degree[v] == 1) {
               valueOfDelete[v] = valueOfDelete[u] + 1;
               q.push_back(v);
            }
         }
      }
   }

   int rem = 0;
   for(int i = 0 ; i < n ; i++) {
      rem += (valueOfDelete[i] > k);
   }

   cout << rem << '\n';
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