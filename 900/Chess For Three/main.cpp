/**
 * created by : cidi mohamed mostepha
 * link : https://codeforces.com/problemset/problem/1973/A
 * rating : 900
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<vector<int>>> dp(31);

void answer()
{
    int a, c, b;
    cin >> a >> b >> c;

    if (a == 0 && b == 0 && c == 0)
    {
        cout << "0\n";
        return;
    }

    auto split = [&](auto self, int x, int y, int z) -> int
    {
        if (x == 0 && y == 0 && z == 0)
        {
            return 0;
        }

        if (x < 0 || y < 0 || z < 0)
            return INT_MIN;

        if (dp[x][y][z] != -1)
            return dp[x][y][z];

        int w1 = self(self, x - 2, y, z);
        int w2 = self(self, x - 1, y - 1, z) + 1;
        int w3 = self(self, x - 1, y, z - 1) + 1;
        int w4 = self(self, x, y - 2, z);
        int w5 = self(self, x, y - 1, z - 1) + 1;
        int w6 = self(self, x, y, z - 2);

        return dp[x][y][z] = max({w1, w2, w3, w4, w5, w6});
    };

    int ans = split(split, a, b, c);

    cout << (ans < 0 ? -1 : ans) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i <= 30; i++)
    {
        dp[i].resize(31);
        for (int j = 0; j <= 30; j++)
        {
            dp[i][j].resize(31);
            for (int k = 0; k <= 30; k++)
                dp[i][j][k] = -1;
        }
    }

    int T = 1;
    cin >> T;

    while (T--)
    {
        answer();
    }

    return 0;
}
