/**
 * created by : cidi mohamed mostepha
 * link : https://codeforces.com/contest/1382/problem/B
 * rating : 1100
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 5e4;

void answer()
{
  int n;
  cin >> n;
  vector<int> vec(n);
  for(int& val : vec) {
    cin >> val;
  }

  int player = 1;
  int is_ones = 1;
  for(int i = 0 ; i < n ; i++) {
    if(vec[i] == 1) {
      player ^= 1;
    } else {
      is_ones ^= 1;
      break;
    }
  }

  cout << (player ^ is_ones ? "First" : "Second") << '\n';
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