/**
 * created by : cidi mohamed mostepha
 * link : https://codeforces.com/contest/1988/problem/A
 * rating : 900
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 5e4;

int split(int n , int k) {
  if(n == 1) {
    return 0;
  }
  if(n <= k) {
    return 1;
  }

  return 1 + split(n - k + 1 , k);
}

void answer()
{
  
  int n , k;
  cin >> n >> k;
  cout << split(n , k) << '\n';
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