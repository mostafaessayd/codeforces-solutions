/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1143/problem/C
rating : 1400
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;


void answer() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> is_respect(n);
    vector<int> parent(n , -1);

    int root = 0;
    for(int i = 0 ; i < n ; i++) {
        int p , c;
        cin >> p >> c;
        p--;
        if(p == -2) {
            root = i;
            continue;
        }
        is_respect[i] = c;
        parent[i] = p;
        adj[p].push_back(i);
    } 
    
    set<int> ans;
    vector<int> vis(n , 0);
    auto dfs = [&](auto self , int u , int p = -1) -> void {
        bool respect = false;
        for(int v : adj[u]) {
            if(v == p) continue;
            self(self , v , u);
            respect |= (is_respect[v] == 0);
        }
        
        if(is_respect[u] == 1 && respect == false && vis[u] == 0) {
            ans.insert(u);
            vis[u]++;
        }

    };

    dfs(dfs , root);
   
    if(ans.size() == 0) {
        cout << "-1";
        return;
    }
    for(int u : ans) cout << u + 1 << ' ';
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



