/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/702/problem/B
rating : 1500
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
  int n;
  cin >> n;
  vector<ll> vec(n);
  map<ll , int> rep;
  for(int i = 0 ; i < n ; i++) {
    cin >> vec[i];
  }

  ll cnt = 0;
  for(int i = 0 ; i < n ; i++) {
    for(int j = 1 ; j <= 30 ; j++) {
      if((1 << j) > vec[i] && rep.count((1 << j) - vec[i])) {
        cnt += rep[(1 << j) - vec[i]];
      }
    }
    rep[vec[i]]++;
  }

 cout << cnt;
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