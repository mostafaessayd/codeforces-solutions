/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1793/problem/C
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
  int n , q;
  cin >> n;
  vector<int> vec(n);
  vector<int> inc_per(n);
  vector<int> dec_per(n);

  for(int i = 0 ; i < n ; i++) {
    cin >> vec[i];
    inc_per[i] = i + 1;
    dec_per[i] = n - i;
  }

  int l = 0;
  int r = n - 1;
  while(l < r) {
    if(vec[l] != dec_per.back() && vec[l] != inc_per.back()) {
      if(vec[r] != inc_per.back() && vec[r] != dec_per.back()) {
        cout << l + 1 << ' ' << r + 1 << '\n';
        return;
      }
    }

    if(vec[l] == inc_per.back()) {
      l++;
      inc_per.pop_back();
    } else if(vec[l] == dec_per.back()) {
      l++;
      dec_per.pop_back();
    }

    if(vec[r] == inc_per.back()) {
      r--;
      inc_per.pop_back();
    } else if(vec[r] == dec_per.back()) {
      r--;
      dec_per.pop_back();
    }
  }

  cout << "-1\n";

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