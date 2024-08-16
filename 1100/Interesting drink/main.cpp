/**
 * created by : cidi mohamed mostepha
 * link : https://codeforces.com/problemset/problem/706/B
 * rating : 1100
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
    int n;
    cin >> n;

    vector<int> vec(n), rep(100001, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        rep[vec[i]]++;
    }

    for (int i = 1; i <= 100000; i++)
        rep[i] += rep[i - 1];

    int q;
    cin >> q;
    while (q--)
    {
        int c;
        cin >> c;

        cout << rep[min(c, 100000)] << '\n';
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
