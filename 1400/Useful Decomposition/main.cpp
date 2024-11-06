/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/981/problem/C
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
    for(int i = 0 ; i < n - 1 ; i++) {
        int u , v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int poss_root = 0;
    int number_of_poss_roots = 0;
    int nbr_leavs = 0;
    for(int i = 0 ; i < n ; i++) {
        nbr_leavs += (adj[i].size() == 1);
        if(adj[i].size() > 2) {
            poss_root = i;
            number_of_poss_roots++;
        }
    }
    
    if(number_of_poss_roots > 1) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        cout << nbr_leavs - (adj[poss_root].size() == 1) << '\n';
        for(int i = 0 ; i < n ; i++) {
            if(i == poss_root) continue;
            if(adj[i].size() == 1) {
                cout << poss_root + 1 << ' ' << i + 1 << '\n';
            }
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



