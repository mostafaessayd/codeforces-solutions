/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1631/problem/B
rating : 1100
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 5e4;

void answer()
{
   int n;
   cin >> n;
   vector<ll> vec(n);
   for(ll& val : vec) {
    cin >> val;
   }

   int ans = 0;
   for(int i = n - 2 ; i > -1 ;) {
    if(vec[i] != vec[n - 1]) {
      ans++;
      i = n - (n - i - 1) * 2 - 1;
    } else {
      i--;
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