/**
 * created by : cidi mohamed mostepha
 * link : https://codeforces.com/contest/1709/problem/B
 * rating : 900
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
  int n , q;
  cin >> n >> q;
  vector<ll> vec(n);
  for(ll& val : vec) {
    cin >> val;
  }

  vector<ll> all_costs_by_right(n , 0);
  ll total_cost = 0;
  for(int i = 0 ; i < n - 1 ; i++) {
    if(vec[i] > vec[i + 1]) {
      total_cost += vec[i] - vec[i + 1];
    }
    all_costs_by_right[i + 1] = total_cost;
  }
  
  vector<ll> all_costs_by_left(n , 0);
  total_cost = 0;
  for(int i = n - 1 ; i > 0 ; i--) {
    if(vec[i] > vec[i - 1]) {
      total_cost += vec[i] - vec[i - 1];
    }
    all_costs_by_left[i - 1] = total_cost;
  }
  while(q--) {
    int l , r;
    cin >> l >> r;
    l--;
    r--;
    if(l <= r) {
      cout << all_costs_by_right[r] - all_costs_by_right[l] << '\n';
    } else {
      cout << all_costs_by_left[r] - all_costs_by_left[l] << '\n';
    }
  }
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