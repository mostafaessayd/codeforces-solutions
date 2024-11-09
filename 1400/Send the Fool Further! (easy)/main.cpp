/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/802/problem/J
rating : 1400
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;


void answer() {
    int n;
    cin >> n;
    vector<vector<pair<int , int>>> adj(n);
    for(int i = 0 ; i < n - 1 ; i++) {
        int u , v , c;
        cin >> u >> v >> c;
        adj[u].push_back({v , c});
        adj[v].push_back({u , c});
    }

    int ans = 0;
    auto dfs = [&](auto self , int u = 0 , int p = -1 , int sum = 0)-> void {
        if(adj[u].size() == 1) {
            ans = max(ans , sum);
        } 
        for(auto v : adj[u]) {
            if(v.first == p) continue;
            self(self , v.first , u , sum + v.second);
        }
    };

    dfs(dfs);

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



