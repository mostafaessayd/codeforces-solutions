/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/982/problem/C
rating : 1500
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using i64 = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0 ; i < n - 1 ; i++) {
    	int x , y;
    	cin >> x >> y;
    	x--;
    	y--;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    }
    
    int ans = 0;
    vector<int> sz(n);
    auto dfs = [&](auto self , int u , int p)->void{
    	sz[u] = 1;
    	for(int v : adj[u]) {
    		if(v != p) {
    			self(self , v , u);
    			sz[u] += sz[v];
    		}
    	}
    	
    	if(sz[u] % 2 == 0) {
    		ans++;
    		sz[u] = 0;
    	}
    };
    
    dfs(dfs , 0 , -1);
    
    cout << (n % 2 ? -1 : ans - 1);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t = 1;
    //std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}