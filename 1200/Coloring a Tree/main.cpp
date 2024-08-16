/**
created by : cidi mohamed mostepha
link : https://codeforces.com/problemset/problem/902/B
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;

int ans = 0;
vector<int> color(1e4, 0);
vector<vector<int>> adj(1e4);
vector<int> vec(1e4);

void dfs(int u, int v)
{
    color[u] = color[v];
    ans += color[u] != vec[u];
    color[u] = vec[u];

    for (int ind : adj[u])
        if (ind != v)
            dfs(ind, u);
}

int main()
{
    int n, x, y;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        cin >> x;
        x--;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    color[0] = vec[0];
    ans++;

    dfs(0, 0);

    cout << ans;
}
