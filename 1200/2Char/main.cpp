/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/593/problem/A
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
    vector<vector<string>> vec(26, vector<string>(26, ""));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        vector<int> rep(26);
        int cur = 0;
        for (char ch : s)
        {
            cur += (rep[ch - 'a'] == 0);
            rep[ch - 'a']++;
        }

        if (cur > 2)
        {
            continue;
        }

        sort(s.begin(), s.end());
        if (s.front() == s.back())
        {
            vec[s.front() - 'a'][s.front() - 'a'] += s;
        }
        else
        {
            vec[s.front() - 'a'][s.back() - 'a'] += s;
            vec[s.back() - 'a'][s.front() - 'a'] += s;
        }
    }

    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        for (int j = i; j < 26; j++)
        {
            ans = max(ans, (int)(vec[i][j].size() + (i != j ? vec[i][i].size() + vec[j][j].size() : 0)));
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