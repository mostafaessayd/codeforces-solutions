/**
created by : cidi mohamed mostepha
link : https://codeforces.com/problemset/problem/1380/A
rating : 900
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
  int n;
  cin >> n;

  vector<int> vec(n);
  vector<int> MIN1(n , 0);
  vector<int> MIN2(n , 0);
  vector<int> indices(n + 1 , 0);

  int ans = INT_MAX;
  for(int i = 0 ; i < n ; i++){
    cin >> vec[i];
    ans = min(ans , vec[i]);
    MIN1[i] = ans;
    indices[vec[i]] = i + 1;
  }

  ans = INT_MAX;
  for(int i = n - 1 ; i > -1 ; i--) {
    ans = min(ans , vec[i]);
    MIN2[i] = ans;
  }

  for(int i = 1 ; i < n - 1 ; i++) {
    if(vec[i] > MIN1[i - 1] && vec[i] > MIN2[i + 1]) {
      cout << "YES\n";
      cout << indices[MIN1[i - 1]] << ' ' << indices[vec[i]] << ' ' << indices[MIN2[i + 1]] << '\n';
      return;
    }
  }

  cout << "NO\n";
}

int main()
{
  int t = 1;
  cin >> t;

  while (t--)
  {
    answer();
  }

  return 0;
}
