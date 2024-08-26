/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/548/problem/A
rating : 1100
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

void answer()
{
    int k;
    string s;
    cin >> s >> k;
    int n = s.size();
    if (n % k)
    {
        cout << "NO";
        return;
    }

    k = n / k;
    for (int i = 0; i <= n - k; i += k)
    {
        for (int j = i, r = 1; j < i + k; j++, r++)
        {
            if (s[j] != s[i + k - r])
            {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES";
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