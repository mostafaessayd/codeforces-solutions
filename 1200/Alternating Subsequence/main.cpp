/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1343/problem/C
rating : 1200
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

void answer()
{
    int n;
    cin >> n;
    vector<ll> vec(n);
    for (ll &val : vec)
    {
        cin >> val;
    }

    ll res = 0;
    for (int i = 0; i < n;)
    {
        int j = i;
        ll ans = -1e9;
        while (j < n)
        {
            if (vec[i] * vec[j] < 0)
            {
                break;
            }
            ans = max(1ll * ans, 1ll * vec[j]);
            j++;
        }
        res += ans;
        i = j;
    }

    cout << res << '\n';
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        answer();
    }
    return 0;
}