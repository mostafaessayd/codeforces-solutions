/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1139/problem/C
rating : 1500
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;
int Mod = 1e9 + 7;

struct DSU {
   vector<int> sz , parent;
   DSU(int n) {
      sz.resize(n , 1);
      parent.resize(n);
      iota(parent.begin() , parent.end() , 0);
   }

   int getParent(int u) {
      if(parent[u] == u) return u;
      return getParent(parent[u]);
   }

   int same(int u , int v) {
      return getParent(u) == getParent(v);
   }

   bool merge(int u , int v) {
      int p1 = getParent(u);
      int p2 = getParent(v);
      if(p1 == p2) return false;
      sz[p1] += sz[p2];
      parent[p2] = p1;
      return true;
   }

   int getSizeOf(int u) {
      return sz[getParent(u)];
   }
};

int Pow(int x , int p) {
   int res = 1;
   while(p--) {
      res = 1ll * res * x % Mod;
   }
   return res;
}

void answer() {
   int n , k;
   cin >> n >> k;
   DSU dsu(n);
   for(int i = 0 ; i < n - 1 ; i++) {
      int u , v , c;
      cin >> u >> v >> c;
      if(c == 1) continue;
      u--;
      v--;
      dsu.merge(u , v);
   }

   set<int> parents;
   for(int i = 0 ; i < n ; i++) {
      parents.insert(dsu.getParent(i));
   }

   int ans = Pow(n , k);
   for(int p : parents) {
      ans = (ans - Pow(dsu.getSizeOf(p) , k) + Mod) % Mod;
   }

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



