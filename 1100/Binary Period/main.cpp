/**
created by : cidi mohamed mostepha
link : https://codeforces.com/problemset/problem/1342/B
rating : 1100
*/


#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 5e4;

void answer()
{
  string s , t = "";
  cin >> s;
  int ones = 0;
  for(char ch : s) {
    ones += (ch == '1');
  }

  if(ones == s.size() || ones == 0) {
    cout << s << '\n';
    return;
  }

  for(int i = 1 ; i < s.size() ; i ++) {
    t += s[i - 1];
    if(s[i] == s[i - 1]) {
      t += (((s[i] - '0') ^ 1) + '0');
    }
  }
  t += s.back();
  cout << t << '\n';
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