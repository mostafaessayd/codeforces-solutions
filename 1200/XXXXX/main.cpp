/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1364/problem/A
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 101;

void answer()
{
  int n , x;
  cin >> n >> x;
  vector<ll> vec(n);
  ll sum = 0;
  bool allDiv = true;
  for(int i = 0 ; i < n ; i++) {
    cin >> vec[i];
    sum += vec[i];
    if(vec[i] % x) {
      allDiv = false;
    }
  }

  if(allDiv) {
    cout << "-1\n";
    return;
  }

  if(sum % x) {
    cout << n << '\n';
  } else {
    int l = 1;
    int i = 0;
    while(vec[i] % x == 0) {
      l++;
      i++;
    }

    i = n - 1;
    int r = 1;
    while(vec[i] % x == 0) {
      i--;
      r++;
    }
    
    cout << max(n - r , n - l) << '\n';
  }
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