/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1559/problem/D1
rating : 1400
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;


void answer() {
    int n , m1 , m2;
    cin >> n >> m1 >> m2;

    vector<int> MochasForest(n);
    vector<int> DianasForest(n);

    for(int i = 0 ; i < n ; i++) {
        MochasForest[i] = i;
        DianasForest[i] = i;
    }
    
    auto getDeepNodeInMochasForestOf = [&](auto self , int u) -> int {
        if(u == MochasForest[u]) return u;
        return MochasForest[u] = self(self , MochasForest[u]);
    };
    auto getDeepNodeInDianasForestOf = [&](auto self , int u) -> int {
        if(u == DianasForest[u]) return u;
        return DianasForest[u] = self(self , DianasForest[u]);
    };

    for(int i = 0 ; i < m1 ; i++) {
        int u , v;
        cin >> u >> v;
        u--;
        v--;
        MochasForest[getDeepNodeInMochasForestOf(getDeepNodeInMochasForestOf , u)] = getDeepNodeInMochasForestOf(getDeepNodeInMochasForestOf , v);
    }
    for(int i = 0 ; i < m2 ; i++) {
        int u , v;
        cin >> u >> v;
        u--;
        v--;
        DianasForest[getDeepNodeInDianasForestOf(getDeepNodeInDianasForestOf , u)] = getDeepNodeInDianasForestOf(getDeepNodeInDianasForestOf , v);
    }
    
    vector<pair<int , int>> adj;
    for(int i = 0 ; i < n - 1 ; i++) {
        for(int j = i + 1 ; j < n ; j++) {
            bool okey = true;
            int x = getDeepNodeInDianasForestOf(getDeepNodeInDianasForestOf , i);
            int y = getDeepNodeInDianasForestOf(getDeepNodeInDianasForestOf , j);
            okey &= (x != y);
            x = getDeepNodeInMochasForestOf(getDeepNodeInMochasForestOf , i);
            y = getDeepNodeInMochasForestOf(getDeepNodeInMochasForestOf , j);
            okey &= (x != y);
            if(okey) {
                adj.push_back({i , j});
                DianasForest[getDeepNodeInDianasForestOf(getDeepNodeInDianasForestOf , i)] = getDeepNodeInDianasForestOf(getDeepNodeInDianasForestOf , j);
                MochasForest[getDeepNodeInMochasForestOf(getDeepNodeInMochasForestOf , i)] = getDeepNodeInMochasForestOf(getDeepNodeInMochasForestOf , j);
            }
        }
    }

    cout << adj.size() << '\n';
    for(auto edge : adj) {
        cout << ++edge.first << ' ' << ++edge.second << '\n';
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



