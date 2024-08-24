/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/90/problem/B
rating : 1100
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 5e4;

void answer()
{
  int n , m;
  cin >> n >> m;
  vector<string> vec(n);
  int R[n][26]{0};
  int C[m][26]{0};
  for(int i = 0 ; i < n ; i++) {
    cin >> vec[i];
    for(int j = 0 ; j < m ; j++) {
      R[i][vec[i][j] - 'a'] += 1;
      C[j][vec[i][j] - 'a'] += 1;
    }
  }

  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) {
      if(R[i][vec[i][j] - 'a'] + C[j][vec[i][j] - 'a'] == 2) {
        cout << vec[i][j];
      }
    }
  }
  cout << '\n';
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