/**
 * created by : cidi mohamed mostepha
 * link : https://codeforces.com/problemset/problem/977/E
 * rating : 1500
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> degree(n, 0);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        degree[x]++;
        degree[y]++;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> vis(n, 0);

    bool flag = true;
    auto dfs = [&](auto self, int start) -> void
    {
        vis[start] = 1;

        flag &= degree[start] == 2;

        for (int vertice : adj[start])
            if (!vis[vertice])
                self(self, vertice);
    };

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;

        flag = true;

        dfs(dfs, i);

        ans += flag;
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    // cin >> T;

    while (T--)
    {
        answer();
    }

    return 0;
}