/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/problemset/problem/217/A
 rating : 1200
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
    int n;
    cin >> n;

    vector<pair<int, int>> vec(n);

    vector<vector<int>> graphe(1001);

    for (int i = 0; i < 1001; i++)
    {
        graphe[i].resize(1001, 0);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i].first >> vec[i].second;
        graphe[vec[i].first][vec[i].second] = 1;
    }

    vector<vector<int>> vis(1001);
    for (int i = 0; i < 1001; i++)
    {
        vis[i].resize(1001, 0);
    }

    auto dfs = [&](auto self, int x, int y) -> void
    {
        if (vis[x][y])
            return;
        vis[x][y] = 1;

        vector<pair<int, int>> nextDest;

        int j = x;
        while (j < 1001)
        {
            if (!vis[j][y] && graphe[j][y])
            {
                nextDest.push_back({j, y});
            }
            j++;
        }

        j = x;
        while (j > 0)
        {
            if (!vis[j][y] && graphe[j][y])
            {
                nextDest.push_back({j, y});
            }
            j--;
        }

        j = y;
        while (j > 0)
        {
            if (!vis[x][j] && graphe[x][j])
            {
                nextDest.push_back({x, j});
            }
            j--;
        }

        j = y;
        while (j < 1001)
        {
            if (!vis[x][j] && graphe[x][j])
            {
                nextDest.push_back({x, j});
            }

            j++;
        }

        for (int i = 0; i < nextDest.size(); i++)
            self(self, (int)nextDest[i].first, (int)nextDest[i].second);
    };

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[vec[i].first][vec[i].second])
            continue;
        ans++;

        dfs(dfs, vec[i].first, vec[i].second);
    }

    cout << ans - 1;
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
