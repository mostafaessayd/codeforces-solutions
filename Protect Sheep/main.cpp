/**
 * created by : cidi mohamed mostepha
 * link : https://codeforces.com/problemset/problem/948/A
 * rating : 900
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
    int R, C;
    cin >> R >> C;

    vector<string> vec(R);

    for (int i = 0; i < R; i++)
        cin >> vec[i];

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (vec[i][j] == '.' || vec[i][j] == 'W')
                continue;

            if (j + 1 < C && j + 1 > -1)
            {
                if (vec[i][j + 1] == 'W')
                {
                    cout << "NO\n";
                    return;
                }
            }

            if (j - 1 < C && j - 1 > -1)
            {
                if (vec[i][j - 1] == 'W')
                {
                    cout << "NO\n";
                    return;
                }
            }

            if (i + 1 < R && i + 1 > -1)
            {
                if (vec[i + 1][j] == 'W')
                {
                    cout << "NO\n";
                    return;
                }
            }

            if (i - 1 < R && i - 1 > -1)
            {
                if (vec[i - 1][j] == 'W')
                {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (vec[i][j] == '.')
            {
                vec[i][j] = 'D';
            }
        }
    }

    cout << "YES\n";

    for (int i = 0; i < R; i++)
        cout << vec[i] << '\n';
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
