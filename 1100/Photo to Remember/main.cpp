/**
 * created by : cidi mohamed mostepha
 * link :https://codeforces.com/contest/522/problem/B
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
    int n;
    cin >> n;
    vector<pair<ll, ll>> vec(n);
    ll sum = 0;
    ll mx1 = -1;
    ll mx2 = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i].first >> vec[i].second;
        sum += vec[i].first;
        if (vec[i].second > mx1)
        {
            swap(mx1, mx2);
            mx1 = vec[i].second;
        }
        else if (vec[i].second > mx2)
        {
            mx2 = vec[i].second;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << (sum - vec[i].first) * (vec[i].second == mx1 ? mx2 : mx1) << ' ';
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
