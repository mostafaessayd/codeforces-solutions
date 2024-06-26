/**
created by : cidi mohamed mostepha
link : https://codeforces.com/problemset/problem/1954/A
rating : 900
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
    int n, m, k;
    cin >> n >> m >> k;

    if ((m - 1) * (n / m) + (n % m ? (n % m) - 1 : 0) <= k)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }
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