/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/23/problem/A
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
    string s;
    cin >> s;
    map<string, int> dp;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        string t = "";
        for (int j = i; j < n; j++)
        {
            t += s[j];
            dp[t]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        string t = "";
        for (int j = i; j < n; j++)
        {
            t += s[j];
            if (dp[t] > 1)
            {
                ans = max(ans, (int)t.size());
            }
        }
    }

    cout << ans;
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