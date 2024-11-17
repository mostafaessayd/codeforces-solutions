/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/1249/problem/B2
 rating : 1300
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
   int n;
   cin >> n;
   vector<int> vec(n);
   DSU dsu(n + 1);
   for(int i = 0 ; i < n ; i++) {
      cin >> vec[i];
      vec[i]--;
      dsu.merge(i , vec[i]);
   }
   
   for(int i = 0 ; i < n ; i++) {
      cout << dsu.getSizeOf(i) << ' ';
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
