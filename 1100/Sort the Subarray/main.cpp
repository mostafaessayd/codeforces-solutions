/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1821/problem/B
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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &val : a)
    {
        cin >> val;
    }
    for (int &val : b)
    {
        cin >> val;
    }
    int x = 0, y = 0;
    int l = 1;
    int cur = 0;
    for (int i = 0; i < n;)
    {
        bool op = false;
        int j = i + 1;
        while (j < n)
        {
            if (b[j] < b[j - 1])
            {
                break;
            }
            if (a[j] != b[j])
                op = true;
            l++;
            j++;
        }
        if (l > cur && op)
        {
            cur = l;
            x = i;
            y = j;
        }
        i = j;
    }

    cout << x + 1 << ' ' << y + (y == n ? 0 : 0) << '\n';
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