/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1769/problem/C1
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int &val : vec)
        cin >> val;
    vector<int> dp(1e6 + 3 , 0);
    for(int i = n - 1 ; i >= 0 ; i--) {
        dp[vec[i]] = max(dp[vec[i]] , dp[vec[i] + 1] + 1);
        dp[vec[i] + 1] = max(dp[vec[i] + 1] , dp[vec[i] + 2] + 1);
    }

    cout << *max_element(dp.begin() , dp.end()) << '\n';
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