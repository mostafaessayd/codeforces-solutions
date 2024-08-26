/**
 * created by : cidi mohamed mostepha
 * link :https://codeforces.com/contest/331/problem/C1
 * rating : 1100
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

void answer()
{
    ll n;
    cin >> n;
    ll ans = 0;
    while (n > 0)
    {
        int mx = 0;
        ll d = n;
        while (d)
        {
            mx = max(1ll * mx, 1ll * (d % 10));
            d /= 10;
        }

        n -= mx;
        ans++;
    }

    cout << ans;
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        answer();
    }
    return 0;
}
