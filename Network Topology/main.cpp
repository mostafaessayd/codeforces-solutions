/**
 * created by : cidi mohamed mostepha
 * link : https://codeforces.com/problemset/problem/292/B
 * rating : 1200
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
    int n, m;
    cin >> n >> m;

    vector<int> degree(n, 0);
    vector<vector<int>> adj(n);

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

    bool star = false;
    bool ring = m == n;
    int startBus = 0;

    for (int i = 0; i < n; i++)
    {
        star |= degree[i] == n - 1;
        ring &= degree[i] == 2;

        if (degree[i] == 1)
        {
            startBus = i;
        }
    }

    star &= m == n - 1;

    if (star)
    {
        cout << "star topology\n";
        return;
    }

    if (ring)
    {
        cout << "ring topology\n";
        return;
    }

    int current = startBus;
    int last = -1;
    int visited = 0;
    bool okey = true;

    while (1)
    {
        if (degree[current] == 1 && !okey)
        {
            visited++;
            break;
        }

        okey = false;

        if (degree[current] > 2 || degree[current] == 0)
        {
            cout << "unknown topology\n";
            return;
        }
        else
        {
            for (int nextVertice : adj[current])
            {
                if (nextVertice != last)
                {
                    last = current;
                    current = nextVertice;
                    visited++;
                    break;
                }
            }
        }
    }

    if (visited == n)
    {
        cout << "bus topology\n";
    }
    else
    {
        cout << "unknown topology\n";
    }
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
