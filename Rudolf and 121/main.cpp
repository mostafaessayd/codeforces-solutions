/**
 * created by : cidi mohamed mostepha
 * link : https://codeforces.com/problemset/problem/1941/B
 * rating : 1000
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
    int n;
    cin >> n;

    vector<int> vec(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    bool lessZero = false;
    for (int i = 0; i < n - 2; i++)
    {
        if (vec[i] == 0)
            continue;
        vec[i + 1] -= vec[i] * 2;
        vec[i + 2] -= vec[i];

        lessZero |= vec[i + 1] < 0 || vec[i + 2] < 0;
    }

    if (vec[n - 2] != 0 || vec[n - 1] != 0)
    {
        lessZero = true;
    }

    lessZero |= vec[n - 1] < 0 || vec[n - 2] < 0;

    cout << (lessZero ? "NO" : "YES") << '\n';
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
