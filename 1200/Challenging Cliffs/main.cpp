/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1537/problem/C
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 2e5 + 1;

void answer()
{
  int n;
  cin >> n;
  vector<int> vec(n , 0);
  for(int i = 1 ; i <= n ; i++) {
    cin >> vec[i - 1];
  }
  
  sort(vec.begin() , vec.end());
  
  if(n == 2) {
    cout << vec[0] << ' ' << vec[1] << '\n';
    return;
  }
  int target = INT_MAX;
  int ind = -1;
  for(int i = 0 ; i < n - 1 ; i++) {
    if(vec[i + 1] - vec[i] <= target) {
      target = vec[i + 1] - vec[i];
      ind = i;
    }
  }

  for(int i = ind + 1 ; i < n ; i++) {
    cout << vec[i] << ' ';
  }
  for(int i = 0 ; i <= ind ; i++) {
    cout << vec[i] << ' ';
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