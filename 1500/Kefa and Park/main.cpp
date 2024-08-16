/**
created by : cidi mohamed mostepha
link : https://codeforces.com/problemset/problem/580/C
rating : 1500
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

void answer()
{
    int n, m;
    cin >> n >> m;

    vector<int> cats(n, 0);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> cats[i];
    }

    vector<vector<int>> adj(n);

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> temp;
    int ans = 0;

    auto dfs = [&](auto self, int u, int p) -> void
    {
        if (adj[u].size() == 1 && p != -1)
        {
            bool okey = true;

            for (int i = 0; i < temp.size();)
            {
                if (cats[temp[i]] == 0)
                {
                    i++;
                }
                else
                {
                    int k = 0;
                    while (i < temp.size())
                    {
                        if (cats[temp[i]] == 0)
                            break;
                        i++;
                        k++;
                    }

                    okey &= k <= m;
                }
            }

            ans += okey;

            return;
        }

        for (int v : adj[u])
        {
            if (v != p)
            {
                temp.push_back(v);
                self(self, v, u);
                temp.pop_back();
            }
        }
    };

    temp.push_back(0);

    dfs(dfs, 0, -1);

    cout << ans;
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
