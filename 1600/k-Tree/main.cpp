/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/431/problem/C
rating : 1600
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;
const int MOD = 1e9 + 7;

void answer() {
   int n , k , d;
   cin >> n >> k >> d;
   
   vector<vector<int>> dp(1000 , vector<int>(2 , -1));
   auto dfs = [&](auto self , int sum = 0 , int status = 0) -> int {
      if(sum > n) return 0;
      if(sum == n && status) return 1; 
      if(dp[sum][status] != -1) return dp[sum][status];
      dp[sum][status] = 0;
      for(int i = 1 ; i <= k ; i++) {
         if(status == 1 || i >= d) {
            dp[sum][status] += self(self , sum + i , 1);
         } else {
            dp[sum][status] += self(self , sum + i , 0);
         }
         dp[sum][status] %= MOD;
      }
      return dp[sum][status];
   };

   cout << dfs(dfs) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
   // cin >> t;
    while(t--) {
        answer();
    }

    return 0;
}