/**
 * created by : cidi mohamed mostepha
 * link : https://codeforces.com/problemset/problem/660/A
 * rating : 1200
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b)
{
    if (b > a)
        swap(a, b);
    return (b == 0 ? a : gcd(b, a % b));
}

void answer()
{
    ll n, k;
    cin >> n;

    vector<ll> pp(n);

    for (int i = 0; i < n; i++)
        cin >> pp[i];

    for (int i = 0; i < pp.size() - 1; i++)
        if (gcd(pp[i], pp[i + 1]) > 1)
            pp.insert(pp.begin() + i + 1, 1);

    cout << pp.size() - n << '\n';
    for (ll ind : pp)
        cout << ind << ' ';
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    //	cin >> T;

    while (T--)
    {
        answer();
    }

    return 0;
}