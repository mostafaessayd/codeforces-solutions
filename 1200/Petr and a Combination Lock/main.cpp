/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1097/problem/B
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 2e5 + 1;
 int n;

bool back_into_zero(int cur , int pos , vector<int>& src) {
  if(pos == n + 1) {
    return (cur == 0 || cur == 360);
  } else {
    int p1 = cur + src[pos];
    if(p1 > 360) {
      p1 %= 360;
    }
    int p2 = cur - src[pos];
    if(p2 < 0) {
     p2 = 360 - abs(p2);
    }
    bool comp1 = back_into_zero(p1 , pos + 1 , src);
    bool comp2 = back_into_zero(p2 , pos + 1 , src);

    return comp1 || comp2;
  }
}

void answer()
{
  cin >> n;
  vector<int> vec(n + 1 , 0);
  for(int i = 1 ; i <= n ; i++) {
    cin >> vec[i];
  }

  cout << (back_into_zero(0 , 0 , vec) ? "YES" : "NO");
}

int main()
{
  ios_base::sync_with_stdio(0);
  int t = 1;
 //cin >> t;
  while (t--)
  {
    answer();
  }

  return 0;
}