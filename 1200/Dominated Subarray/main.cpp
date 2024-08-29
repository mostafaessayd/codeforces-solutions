/**
created by : cidi mohamed mostepha
link :https://codeforces.com/contest/1257/problem/C
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 101;

void answer()
{
  int n;
  cin >> n;
  vector<ll> vec(n);
  for(int i = 0 ; i < n ; i++) {
    cin >> vec[i];
  }
  
  vector<int> dp(n + 1 , 0);
  int ans = INT_MAX;
  int j = 0;
  for(int i = 0 ; i < n ; i++) {
    while(j < n) {
      if(dp[vec[j]] == 1) {
        break;
      }
      dp[vec[j]]++;
      j++;
    }
    if(j == n) {
      break;
    }
    ans = min(ans , j - i + 1);
    dp[vec[i]]--;
  }

  cout << (ans == INT_MAX ? -1 : ans) << "\n";
}

int main()
{
  ios_base::sync_with_stdio(0);
  int t = 1;
  cin >> t;
  while (t--)
  {
    answer();
  }

  return 0;
}