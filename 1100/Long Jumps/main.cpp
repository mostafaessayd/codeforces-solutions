/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/problemset/problem/1472/C
 rating : 1100
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
    int n;
    cin >> n;

    vector<ll> vec(n);

    for (ll &value : vec)
        cin >> value;

    vector<int> dp(n);

    for (int i = n - 1; i >= 0; i--)
    {
        dp[i] = vec[i];

        int nextIndexe = i + vec[i];

        if (nextIndexe < n)
        {
            dp[i] += dp[nextIndexe];
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';
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
