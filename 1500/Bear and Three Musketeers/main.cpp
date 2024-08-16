/**
created by : cidi mohamed mostepha
link : https://codeforces.com/problemset/problem/574/B
rating : 1500
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
    vector<vector<bool>> isEdge(n);

    for (int i = 0; i < n; i++)
    {
        isEdge[i].resize(n, false);
    }

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        adj[x].push_back(y);
        adj[y].push_back(x);

        isEdge[x][y] = isEdge[y][x] = true;

        degree[x]++;
        degree[y]++;
    }

    int ans = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (degree[i] > 1)
        {
            for (int j = 0; j < adj[i].size() - 1; j++)
            {
                for (int k = j + 1; k < adj[i].size(); k++)
                {
                    if (adj[i][j] != adj[i][k])
                    {
                        if (isEdge[adj[i][j]][adj[i][k]])
                        {
                            int totalDegree = degree[adj[i][j]] + degree[adj[i][k]] + degree[i];
                            ans = min(ans, totalDegree - 6);
                        }
                    }
                }
            }
        }
    }

    cout << (ans == INT_MAX ? -1 : ans);
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
