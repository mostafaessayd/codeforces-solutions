/**
created by : cidi mohamed mostepha
link :https://codeforces.com/problemset/problem/697/A
rating : 900
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
    int t, s, x;
    cin >> t >> s >> x;

    if (x == t)
    {
        cout << "YES\n";
        return;
    }

    if (x < s + t)
    {
        cout << "NO\n";
        return;
    }

    int a1 = x - t;
    int b1 = x - t;

    int a2 = x - 1 - t;
    int b2 = x - 1 - t;

    if ((a1 % s == 0 && b1 % s == 0) || (a2 % s == 0 && b2 % s == 0))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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