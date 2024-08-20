/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1669/problem/D
rating : 1100
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 5e4;

void answer()
{
  int n;
  string s;
  cin >> n >> s;
  for(int i = 0 ; i < n ; ) {
    int j = i;
    string temp = "";
    int r = 0;
    while(j < n) {
      if(s[j] == 'W') {
        break;
      }
      r += (s[j] == 'R');
      temp += s[j];
      j++;
    }

    i = j + 1;
      if(temp == "") {
        continue;
      }
      if(r == 0 || r == temp.size()) {
        cout << "NO\n";
        return;
      }
  }

  cout << "YES\n";
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