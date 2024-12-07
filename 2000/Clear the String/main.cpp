/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1132/problem/F
rating : 2000
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
    int n;
    string s;
    cin >> n >> s;
    vector<vector<ll>> dp(n , vector<ll>(n , -1));
    auto f = [&](auto self , int i , int j) -> int {
        if(i > j) return 0;
        if(~dp[i][j]) return dp[i][j];
        int ans = min(self(self , i + 1 , j) , self(self , i , j - 1)) + 1;
        for(int k = i + 1 ; k <= j ; k++) {
            if(s[i] == s[k])
            ans = min(ans , self(self , i + 1 , k) + self(self , k + 1 , j));
        } 
        return dp[i][j] = ans;
    };

    cout << f(f , 0 , n - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        answer();
    }

    return 0;
}