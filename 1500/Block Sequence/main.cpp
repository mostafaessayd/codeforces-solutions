/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1881/problem/E
rating : 1500
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
    
    vector<vector<int>> dp(n , vector<int>(2 , -1));
    auto f = [&](auto self , int idx , int take) -> ll {
        if(idx == n) return 0;
        if(idx > n) return INT_MAX;
        if(~dp[idx][take]) return dp[idx][take];
        return dp[idx][take] = min(self(self , idx + vec[idx] + 1 , 1) , 1 + self(self , idx + 1 , 0));
    };

    cout << min(f(f , 0 , 0) , f(f , 0 , 1)) << '\n';
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