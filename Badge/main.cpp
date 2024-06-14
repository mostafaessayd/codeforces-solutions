/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/problemset/problem/1020/B
 rating : 1000
 */
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
    int n;
    cin >> n;

    vector<int> nextOne(n, 0);
    vector<int> vec(n);

    for(int i = 0 ; i < n ; i++)
    {
        cin >> vec[i];
        vec[i]--;

        nextOne[i] = vec[i];
    }

    vector<int> vis(n, 0);

    auto dfs = [&](auto self, int x)->int
    {
        if(vis[x] == 1)
            return x + 1;
        vis[x] = 1;
        return self(self, nextOne[x]);
    };

    for(int i = 0 ; i < n ; i++)
    {
        vis.assign(n, 0);
        cout << dfs(dfs, i) << ' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int T = 1;
    // cin >> T;

    while (T--)
    {
        answer();
    }

    return 0;
}
