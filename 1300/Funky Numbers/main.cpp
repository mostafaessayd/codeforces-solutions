/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/1900/problem/C
 rating : 1300
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

void answer()
{
    map<ll, int> dp;
    ll ans = 0;
    ll cur = 1;
    while (ans < 1e9)
    {
        ans += cur;
        dp[ans]++;
        cur++;
    }

    ll n;
    cin >> n;

    for (auto ind : dp)
    {
        if (dp[n - ind.first] && dp[ind.first])
        {
            cout << "YES";
            return;
        }
    }

    cout << "NO";
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