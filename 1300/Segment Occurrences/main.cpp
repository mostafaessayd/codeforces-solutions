/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/1016/problem/B
 rating : 1300
 */


#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e3 + 1;

void answer()
{
  int n , m , q;
  string t , s;
  cin >> n >> m >> q >> s >> t;
  vector<vector<int>> dp(N , vector<int>(N , 0));
  for(int i = 0 ; i < n ; i++) {
    int res = 0;
    string temp = "";
    for(int j = i ; j < n ; j++) {
      temp += s[j];
      if(temp.size() >= t.size()) {
        res += (temp.substr(temp.size() - t.size() , t.size()) == t);
      }
      dp[i][j] = res;
    }
  }

  while(q--) {
    int l , r;
    cin >> l >> r;
    cout << dp[l - 1][r - 1] << '\n';
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  int t = 1;
  //cin >> t;
  while (t--)
  {
    answer();
  }

  return 0;
}