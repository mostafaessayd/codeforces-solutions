/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1354/problem/B
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 5e4;

void answer()
{
  string s;
  cin >> s;
  int n = s.size();
  
  vector<int> rep(4);
  int j = 0;
  int ans = INT_MAX;
  for(int i = 0 ; i < n ; i++) {
    while(j < n) {
      if(rep[1] && rep[2] && rep[3]) {
        break;
      }
      rep[s[j] - '0']++;
      j++;
    }
    if(j == n) {
      if(rep[1] && rep[2] && rep[3]) {
        ans = min(ans , j - i);
      } else {
        break;
      }
    } else if(j > n) {
      break;
    }
    ans = min(ans , j - i);
    rep[s[i] - '0']--;
  }

  cout << (ans <= n ? ans : 0) << '\n';
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