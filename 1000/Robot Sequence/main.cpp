/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/626/problem/A
 rating : 1000
 */


#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 5e4;

void answer()
{
  string s;
  int n;
  cin >> n >> s;
  int ans = 0;
  for(int i = 0 ; i < s.size() ; i++) {
    int x = 0 , y = 0;
    for(int j = i ; j < s.size() ; j++) {
      if(s[j] == 'L') {
        x++;
      }
      if(s[j] == 'R') {
        x--;
      }
      if(s[j] == 'U') {
        y++;
      }
      if(s[j] == 'D') {
        y--;
      }

      if(x == 0 && y == 0) {
        ans++;
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