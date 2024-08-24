/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/474/problem/B
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
    vector<ll> a(n);
    cin >> a[0];
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    int m;
    cin >> m;
    while (m--)
    {
        ll x;
        cin >> x;
        int l = 0;
        int r = n - 1;
        int ans = n - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (a[mid] >= x)
            {
                r = mid;
                ans = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        cout << ans + 1 << '\n';
    }
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