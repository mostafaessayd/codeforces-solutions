/**
created by : cidi mohamed mostepha
link : https://codeforces.com/problemset/problem/1076/B
rating : 1200
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

using namespace std;
using ll = long long;

bool prime(ll a, ll b)
{
    return (b == 1 ? true : (a % b ? prime(a, b - 1) : false));
}

void answer()
{
    ll n, k;
    cin >> n;

    if (prime(n, sqrt(n)))
        cout << 1;
    else
    {
        ll ans = 0;
        while (n > 0)
        {
            if (n % 2 == 0)
            {
                ans += n / 2;
                break;
            }

            ll i = 2;
            bool flag = true;
            while (1)
            {
                if (prime(i, sqrt(i)))
                    if (n % i == 0)
                        break;
                i++;
            }

            n -= i;
            ans++;
        }

        cout << ans << '\n';
    }
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(0);
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