/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/698/problem/A
rating : 1400
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
    
    vector<vector<int>> dp(n , vector<int>(3 , -1));
    
    auto f = [&](auto self , int idx , int last) -> int {
        if(idx == n) return 0;
        if(~dp[idx][last]) return dp[idx][last];
        int ans = self(self , idx + 1 , 2);
        if(last == 0) {
            if(vec[idx] == 1 || vec[idx] == 3) {
                ans = max(ans , 1 + self(self , idx + 1 , 1));
            }
        } else {
            if(last == 1) {
                if(vec[idx] == 2 || vec[idx] == 3) {
                    ans = max(ans , 1 + self(self , idx + 1 , 0));
                }
            } else {
                if(vec[idx] == 1 || vec[idx] == 3) {
                    ans = max(ans , 1 + self(self , idx + 1 , 1));
                }
                if(vec[idx] == 2 || vec[idx] == 3) {
                    ans = max(ans , 1 + self(self , idx + 1 , 0));
                }
            }
        }

        return dp[idx][last] = ans;
    };

    cout << n - f(f , 0 , 2);
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