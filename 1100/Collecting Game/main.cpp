/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1904/problem/B
rating : 1100
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 5e4;

void answer()
{
  
  int n;
  cin >> n;
  vector<ll> src(n) , vec(n);
  for(int i = 0 ; i < n ; i++) {
    cin >> vec[i];
    src[i] = vec[i];
  }

  map<ll , ll> prefix;
  map<ll , ll> dp;
  sort(vec.begin() , vec.end());
  
  ll ans = 0;
  for(int i = n - 1 ; i > -1 ; i--) {
    ans += vec[n - i - 1];
    prefix[vec[n - i - 1]] = ans;
  
    if(dp[vec[i]] == 0) {
      dp[vec[i]] = i; 
    }
  }
  
  for(int i = n - 1 ; i > -1 ; i--) {
    ll score = prefix[vec[i]];
    if(score >= vec[n - 1]) {
       dp[vec[i]] = (dp[vec[n - 1]] > dp[vec[i]] ? dp[vec[n - 1]] : dp[vec[i]]);
       continue;
    }
    int l = 1;
    int r = n;
    int ind = -1;
    while(l < r) {
      int mid = (l + r) / 2;
      if(vec[mid - 1] > score) {
        r = mid;
      } else {
        ind = mid - 1;
        l = mid + 1;
      }
    }
    if(~ind) {
      dp[vec[i]] = (dp[vec[ind]] > dp[vec[i]] ? dp[vec[ind]] : dp[vec[i]]);
    }
  }

  for(int i = 0 ; i < n ; i++) {
   cout << dp[src[i]] << " \n"[i == n - 1];
  }
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