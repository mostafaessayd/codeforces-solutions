/**
created by : cidi mohamed mostepha
link : https://codeforces.com/problemset/problem/500/A
rating : 1000
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
    int n, t;
    cin >> n >> t;

    vector<int> vec(n - 1);

    for (int i = 0; i < n - 1; i++)
        cin >> vec[i];

    vector<int> vis(n + 1, 0);

    bool found = false;
    int start = 1;

    while (!found)
    {
        if (vis[start])
            break;
        found = start == t;
        vis[start] = 1;

        if (start - 1 > -1 && start - 1 <= n - 2)
            start += vec[start - 1];
    }

    cout << (found ? "YES\n" : "NO\n");
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