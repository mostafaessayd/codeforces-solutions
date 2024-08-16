/**
created by : cidi mohamed mostepha
link : https://codeforces.com/problemset/problem/1971/D
rating : 1100
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 5e4;

void answer()
{
  string s;
  cin >> s;
  
  vector<char> press_array;
  for(int i = 0 ; i < s.size() ; ) {
    int j = i;
    press_array.push_back(s[i]);
    while(i < s.size()) {
      if(s[i] != s[j]) {
        break;
      }
      i++;
    }
  }
  
  int ans = INT_MAX;
  int n  = press_array.size();
  for(int i = 0 ; i < n - 1 ; i++) {
    if(press_array[i] == '0' && press_array[i] != press_array[i + 1]) {
      ans = min(ans , n - 1);
      break;
    }
  }

  if(ans == INT_MAX) {
    if(press_array[0] == press_array[n - 1]) {
      ans = 1;
    } else {
      ans = 2;
    }
  }

  cout << ans << '\n';
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