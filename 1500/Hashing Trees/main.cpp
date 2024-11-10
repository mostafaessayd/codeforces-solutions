/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/901/problem/A
rating : 1500
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;


void answer() {
   int h;
   cin >> h;
   vector<int> heights(h + 1);
   for(int& height : heights) cin >> height;

   bool perfect = true;
   for(int i = 1 ; i <= h ; i++) {
    if(heights[i - 1] != 1 && heights[i] != 1) {
        perfect = false;
        break;
    }
   }

   if(perfect) {
    cout << "perfect";
   } else {
     int n = accumulate(heights.begin() , heights.end() , 0);
     vector<vector<int>> adj(n);
     int current_vertice = 1;
     vector<int> parent(n , -1);
     for(int i = 0 ; i < heights[1] ; i++) {
        adj[0].push_back(current_vertice);
        parent[current_vertice] = 0;
        current_vertice++;
     }
     int last_vertice = current_vertice - 1;
     for(int i = 2 ; i <= h ; i++) {
        for(int j = 0 ; j < heights[i] ; j++) {
           adj[last_vertice].push_back(current_vertice);
           parent[current_vertice] = last_vertice;
           current_vertice++;
        }
        last_vertice = current_vertice - 1;
     }
     
     cout << "ambiguous\n";
     for(int i = 0 ; i < n ; i++) {
        cout << parent[i] + 1 << ' ';
     }

     auto dfs = [&](auto self , int u = 0 , int p = -1) -> void {
        if(adj[u].size() > 1 && adj[adj[u][adj[u].size() - 1]].size() > 1) {
            for(int i = adj[adj[u][adj[u].size() - 1]].size() - 1 ; i >= 0 ; i--) {
                 parent[adj[adj[u][adj[u].size() - 1]][i]] = adj[u][0];
                 break;
            }
            return;
        }
        for(int v : adj[u]) {
            if(v == p) continue;
            self(self , v , u);
        }
     };

     dfs(dfs);

     cout << '\n';
     for(int i = 0 ; i < n ; i++) {
        cout << parent[i] + 1 << ' ';
     }
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



