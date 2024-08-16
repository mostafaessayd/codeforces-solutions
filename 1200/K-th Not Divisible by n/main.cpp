/**
 * created by : cidi mohamed mostepha
 * link : https://codeforces.com/problemset/problem/1352/C
 * rating : 1200
 */

#include <iostream>
using namespace std;

int main()
{
    long long x, y, t[1000], n, i;
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        cin >> x >> y;
        if (x > y)
            t[i] = y;
        if (x == y)
            t[i] = x + 1;
        if (x == 0)
            t[i] = y;

        if (x < y)
        {
            long long d = ((x * y) / (x - 1));
            if (d % x == 0)
                t[i] = d - 1;
            else
                t[i] = d;
        }
    }

    for (i = 1; i <= n; i++)
        cout << t[i] << "\n";
}