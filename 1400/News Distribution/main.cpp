/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1167/problem/C
rating : 1400
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;

struct DSU {
   vector<int> sz , parent;
   DSU(int n) {
      sz.resize(n , 1);
      parent.resize(n);
      iota(parent.begin() , parent.end() , 0);
   }

   int getParent(int u) {
      if(parent[u] == u) return u;
      return parent[u] = getParent(parent[u]);
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

void answer() {
   int n , m;
   cin >> n >> m;
   DSU dsu(n + 1);
   while(m--) {
      int k;
      cin >> k;
      int last = -1;
      while(k--) {
         int x;
         cin >> x;
         if(last != -1) {
            dsu.merge(last , x);
         }
         last = x;
      }
   }

   for(int i = 1 ; i <= n ; i++) {
      cout << dsu.getSizeOf(i) << ' ';
   }
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
