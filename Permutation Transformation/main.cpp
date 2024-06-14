/**
 created by : 
 link : https://codeforces.com/problemset/problem/1490/D
 rating : 1200
*/
#include <bits/stdc++.h>

using namespace std;

void answer()
{
    int n;
    cin >> n;

    vector<int> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    vector<int> depth(n + 1, 0);

    auto dfs = [&](auto self, int start, int last, int d) -> void
    {
        if (start <= last)
        {

            int ind = start;
            int cur = vec[start];
            for (int i = start; i <= last; i++)
                if (vec[i] > cur)
                {
                    cur = vec[i];
                    ind = i;
                }

            depth[vec[ind]] = d;
            self(self, start, ind - 1, d + 1);
            self(self, ind + 1, last, d + 1);
        }
    };

    dfs(dfs, 0, n - 1, 0);

    for (int i = 0; i < n; i++)
        cout << depth[vec[i]] << ' ';
    cout << '\n';
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
