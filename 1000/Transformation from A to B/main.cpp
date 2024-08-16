/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/problemset/problem/727/A
 rating : 1000
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
    int a, b;
    cin >> a >> b;

    vector<string> steps(2e5, "");

    auto split = [&](auto self, ll x, ll y, int d, string s) -> ll
    {
        if (x > y)
        {
            return INT_MAX;
        }

        if (x == y)
        {
            steps[d] = s;
            return 0;
        }
        else
        {
            ll l1 = self(self, x * 10 + 1, y, d + 1, s + "1") + 1;
            ll l2 = self(self, x * 2, y, d + 1, s + "2") + 1;

            return min(1ll * l1, 1ll * l2);
        }
    };

    ll ans = split(split, a, b, 0, "");
    ll cur = ans - INT_MAX;

    if (cur <= 0)
    {
        cout << "YES\n"
             << ans + 1 << '\n';
        ll start = a;
        for (char ch : steps[ans])
        {
            cout << start << ' ';
            start = (ch == '1' ? start * 10 + 1 : start * 2);
        }

        cout << b;
    }
    else
    {
        cout << "NO\n";
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
