/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/665/problem/C
 rating : 1300
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
  string s;
  cin >> s;
  int n = s.size();

  for(int i = 1 ; i < n - 1 ; i++) {
    if(s[i] != s[i - 1]) {
      continue;
    }
    for(int j = 0 ; j < 26 ; j++) {
      if(s[i] != (char)(j + 'a') && (char)(j + 'a') != s[i + 1]) {
        s[i] = (char)(j + 'a');
        break;
      }
    }
  }
  
  if(s[n - 1] == s[n - 2]) {
    for(int j = 0 ; j < 26 ; j++) {
      if(s[n - 2] != (char)(j + 'a')) {
        s[n - 1] = (char)(j + 'a');
        break;
      }
    }
  }
  cout << s;
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