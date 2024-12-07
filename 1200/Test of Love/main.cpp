/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1992/problem/D
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
    int n , k ,m;
    string river;
    cin >> n >> m >> k >> river;
    river = 'L' + river;
    vector<int> dp(n + 2 , 1e6);
    dp[0] = 0;
    for(int i = 0 ; i <= n ; i++) {
        if(river[i] == 'C') continue;
        for(int j = 1 ; j <= m ; j++) {
            if(i - j >= 0 && river[i - j] == 'L') {
                dp[i] = min(dp[i] , dp[i - j]);
            }
        }
        if(river[i] == 'W') {
            dp[i + 1] = min(dp[i + 1] , dp[i] + 1);
        }
    }
    for(int j = 1 ; j <= m ; j++) {
            if(n + 1 - j >= 0 && river[n + 1 - j] == 'L') {
                dp[n + 1] = min(dp[n + 1] , dp[n + 1 - j]);
            }
        }
    cout << (dp[n + 1] <= k ? "YES" : "NO") << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
     cin >> t;
    while (t--)
    {
        answer();
    }

    return 0;
}