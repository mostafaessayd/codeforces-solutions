/**
created by : cidi mohamed mostepha
link : https://codeforces.com/problemset/problem/1255/B
rating : 1100
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
using ll = long long;

void answer()
{
    int n, m;
    cin >> n >> m;

    vector<int> vec(n);
    map<int, vector<int>> dp;

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        dp[vec[i]].push_back(i);
    }

    if (m < n || n == 2)
    {
        cout << "-1\n";
        return;
    }

    vector<int> finalVec;
    for (auto &[x, y] : dp)
    {
        for (int ind : y)
            finalVec.push_back(ind);
    }

    int c = 0;
    int g = n;

    vector<pair<int, int>> ans;

    for (int i = 0; i < finalVec.size() - 1 && g; i++)
    {
        c += vec[finalVec[i]] + vec[finalVec[i + 1]];
        ans.push_back({finalVec[i], finalVec[i + 1]});
        g--;
        m--;
    }

    c += vec[finalVec[0]] + vec[finalVec.back()];
    ans.push_back({finalVec[0], finalVec.back()});
    m--;

    while (m--)
    {
        c += vec[finalVec[0]] + vec[finalVec[1]];
        ans.push_back({finalVec[0], finalVec[1]});
    }

    cout << c << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    cin >> T;

    while (T--)
    {
        answer();
    }

    return 0;
}