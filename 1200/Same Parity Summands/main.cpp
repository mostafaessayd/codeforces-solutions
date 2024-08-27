/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1352/problem/B
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 5e4;

void answer()
{
  int n , k;
  cin >> n >> k;
  bool odd = ((n - k + 1) % 2 != 0 && (n - k + 1) > 0);
  bool even = ((n - 2 * k + 2) % 2 == 0 && (n - 2 * k + 2) > 0);

  if(!odd && !even) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    if(even) {
      for(int i = 0 ; i < k - 1 ; i++) {
        cout << "2 ";
      }
      cout << (n - 2 * k + 2);
    } else {
      for(int i = 0 ; i < k - 1 ; i++) {
        cout << "1 ";
      }
      cout << (n - k + 1); 
    }
  }

  cout << '\n';
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