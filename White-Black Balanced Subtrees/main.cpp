/**
created by cidi mohamed mostepha
link : https://codeforces.com/problemset/problem/1676/G
rating : 1300
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<vector<int>> ADJList;
vector<int> vis;
vector<pair<int, int>> colorOfVertices;

int ans = 0;

void DFS(int u, int v, string &color)
{
    if (ADJList[u].size() == 1 && ADJList[u][0] == v)
    {
    }
    else
    {
        for (int ind : ADJList[u])
        {
            if (ind != v)
            {
                DFS(ind, u, color);

                colorOfVertices[u].first += colorOfVertices[ind].first;
                colorOfVertices[u].second += colorOfVertices[ind].second;
            }
        }
    }
}

void answer()
{
    int n, x;
    cin >> n;

    ADJList.clear();
    ADJList.resize(n);
    colorOfVertices.clear();
    colorOfVertices.resize(n, {0, 0});
    vis.clear();
    vis.resize(n, 0);
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        x--;
        ADJList[x].push_back(i);
        ADJList[i].push_back(x);
    }

    string s;
    cin >> s;

    for (int i = 0; i < n; i++)
    {
        colorOfVertices[i].first += s[i] == 'W';
        colorOfVertices[i].second += s[i] == 'B';
    }

    ans = 0;
    DFS(0, -1, s);

    for (int i = 0; i < n; i++)
    {
        ans += colorOfVertices[i].first == colorOfVertices[i].second;
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    cin >> T;

    while (T--)
    {
        answer();
    }

    return 0;
}
