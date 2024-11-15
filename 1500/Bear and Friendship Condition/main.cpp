/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/771/problem/A
rating : 1500
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <deque>
#include <set>

using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;

void answer() {
	int n , m;
	cin >> n >> m;
	vector<vector<int>> adj(n);

	for(int i = 0 ; i < m ; i++) {
		int u , v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<int> vis(n , 0);
	auto dfs = [&](auto self , int u , ll& ed) -> ll {
		if(vis[u]) return 0;
		vis[u]++;
		ed += 1ll * adj[u].size();
		ll ans = 1;
		for(int v : adj[u]) {
			ans += self(self , v , ed);
		}
		return ans;
	};
	
	bool good = true;
	for(int i = 0 ; i < n ; i++) {
		if(vis[i]) continue;
		ll x = 0;
		ll vertices = dfs(dfs , i , x);
		vertices = (vertices * (vertices - 1)) / 2;
		good &= (vertices == x / 2);
	}
	
	cout << (good ? "YES" : "NO");
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