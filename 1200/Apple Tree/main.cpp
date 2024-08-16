/**
created by : cidi mohamed mostepha
link : https://codeforces.com/problemset/problem/1843/D
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll> degree(2e5, 0);
vector<int> vis(2e5, 0);
vector<vector<int>>ADJList;

void DFS(int u, int v)
{
    if(ADJList[u].size() == 1 && ADJList[u][0] == v)
        degree[u] = 1;
    else
    {
        for(int ind : ADJList[u])
        {
            if(ind != v)
            {
                DFS(ind, u);
                degree[u] += degree[ind];
            }
        }
    }
}

void answer()
{
    int n;
    cin >> n;;

    ADJList.clear();
    ADJList.resize(n);
    degree.assign(n, 0);
    vis.assign(n, 0);

    for(int i = 0 ; i < n - 1 ; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        ADJList[x].push_back(y);
        ADJList[y].push_back(x);
    }

    DFS(0, -1);

    int q;
    cin >> q;
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        ll ans = degree[x - 1] * degree[y - 1];
        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    cin >> T;

    while(T--)
    {
        answer();
    }

    return 0;
}
