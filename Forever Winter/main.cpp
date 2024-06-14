/**
created by : cidi mohamed mostepha
link : https://codeforces.com/problemset/problem/1829/F
rating : 1300
*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(1e4);

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, x, y, m;
        cin >> n >> m;

        adj.clear();
        adj.resize(n);

        for (int i = 1; i <= m; i++)
        {
            cin >> x >> y;
            x--;
            y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<int> children;
        for (int i = 0; i < n; i++)
            if (adj[i].size() == 1)
                children.push_back(i);

        vector<int> dg(n, 0);
        for (int ind : children)
        {
            dg[adj[ind][0]]++;
            for (auto u : adj[adj[ind][0]])
                if (adj[u].size() != 1)
                    dg[u]++;
        }

        for (auto u : adj[adj[children[0]][0]])
            if (adj[u].size() != 1)
            {
                cout << dg[u] / dg[adj[children[0]][0]] << ' ';
                break;
            }

        cout << dg[adj[children[0]][0]] << '\n';
    }
}
