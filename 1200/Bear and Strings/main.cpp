/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/385/problem/B
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 101;

void answer()
{
  string s;
  cin >> s;
  int n = s.size();

  string target = "bear";
  int ans = 0;
  int last_used = 0;
  for(int i = 0 ; i < n ; i++) {
    if(s[i] == target[0]) {
      int j = i;
      int k = 0;
      while(j < n) {
        if(s[j] != target[k]) {
          break;
        }
        j++;
        k++;
      }
      if(k == 4) {
        ans += (i - last_used + 1) * (n - i - 3);
        last_used = i + 1;
      }
    }
  }

  cout << ans;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int t = 1;
 // cin >> t;
  while (t--)
  {
    answer();
  }

  return 0;
}