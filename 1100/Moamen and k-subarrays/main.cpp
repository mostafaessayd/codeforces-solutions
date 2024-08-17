/**
created by : cidi mohamed mostepha
link : https://codeforces.com/problemset/problem/1557/B
rating : 1100
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 5e4;

void answer()
{
  int n , k;
  cin >> n >> k;
  vector<int> vec(n);
  map<int , int> indices;
  map<int , int> vis;
  vector<int> values;
  for(int i = 0 ; i < n ; i++) {
    cin >> vec[i];
    indices[vec[i]] = i;
    values.push_back(vec[i]);
  }
  
  sort(values.begin() , values.end());

  int l = 0;
  for(int i = 0 ; i < n ; i++) {
    if(vis[values[i]] == 1) {
      continue;
    }
    int j;
    int ind;
    for(j = indices[values[i]] , ind = i ; j < n && ind < n ; j++ , ind++) {
      if(vec[j] != values[ind]) {
        l++;
        break;
      }
      vis[vec[j]] = 1;
    }
    if(ind == n || j == n) {
      l++;
    } 
  }

  cout << (l <= k ? "YES" : "NO") << "\n";
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