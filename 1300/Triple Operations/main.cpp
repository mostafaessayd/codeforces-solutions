/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/1999/problem/E
 rating : 1300
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {

  vector<int> dp(2e5 + 1);
  vector<int> prefix_sum(2e5 + 1);
  dp[0] = 0;
  dp[1] = dp[2] = 1;
  int sum = 0;
  prefix_sum[1] = 1;
  prefix_sum[2] = 2;
  for(int i = 3 ; i <= 2e5 ; i++) {
    dp[i] = dp[i / 3] + 1;
    prefix_sum[i] = prefix_sum[i - 1] + dp[i];
  }
  
  int n;
  cin >> n;
  while(n--) {
    int l , r;
    cin >> l >> r;
    cout << prefix_sum[r] - prefix_sum[l - 1] + dp[l] << '\n';
  }
}