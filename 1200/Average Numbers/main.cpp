/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/134/problem/A
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
    ll sum = 0;
    for (ll &val : vec)
    {
        cin >> val;
        sum += val;
    }

    vector<int> ind;
    for (int i = 1; i <= n; i++)
    {
        if (vec[i - 1] == (sum - vec[i - 1]) / (n - 1) && (sum - vec[i - 1]) % (n - 1) == 0)
        {
            ind.push_back(i);
        }
    }

    cout << ind.size() << '\n';
    for (ll val : ind)
    {
        cout << val << ' ';
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