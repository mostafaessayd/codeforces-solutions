/**
 created by : cidi mohamed mostepha
 link :https://codeforces.com/contest/598/problem/B
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

  int q;
  cin >> q;
  while(q--) {
    int l , r , k;
    cin >> l >> r >> k;
    l--;
    r--;

    string left = s.substr(0 , l);
    string middle = s.substr(l , r - l + 1);
    string right = s.substr(r + 1 , n - r - 1);

    k %= middle.size();
    string a = middle.substr(0 , middle.size() - k);
    string b = middle.substr(middle.size() - k , k);

    middle = b + a;
    s = left + middle + right;
  }

  cout << s << '\n';
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